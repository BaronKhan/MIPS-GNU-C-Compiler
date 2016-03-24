#!/bin/bash

COMPILER=bin/c_compiler

# TODO: Make sure this points to your own mips gcc.
MIPS_GCC=mips-linux-gnu-gcc

cd ..
(make bin/c_compiler)

for i in test/input/*.c; do
  BASE=$(basename $i .c);

  ###################################
  ## Reference (native) version
  
  #${MIPS_GCC} -static $i -o build/$BASE.ref.s
  gcc $i -o test/build/$BASE.ref
  ./test/build/$BASE.ref
  echo $? > test/output/$BASE.ref
  ###################################
  ## Tested (MIPS) version

  # TODO: C pre-processor?
  cat $i | ./$COMPILER > test/build/$BASE.got.s
  # Make sure this is set to a MIPS GCC above
  ${MIPS_GCC} -static test/build/$BASE.got.s -o test/build/$BASE.got
  #This will work if QEMU is installed
  #test/build/$BASE.got
  qemu-mips test/build/$BASE.got
  echo $? > test/output/$BASE.got

  ##################################
  ## Compare the output
  diff test/output/$BASE.got test/output/$BASE.ref > test/output/$BASE.diff;
  if [[ $? != 0 ]]; then
    echo "$BASE, FAIL, see output/$BASE.diff";
  else
    echo "$BASE, pass";
  fi
done
