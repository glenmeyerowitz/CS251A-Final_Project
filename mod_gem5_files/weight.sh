#!/bin/bash

GEM5_BASE=~/gem5
SRC_DIR=~/CS251A-Final_Project/mnist-test
RESULT_DIR=~/result
TARGET=~/gem5/configs/example/se.py


cd $GEM5_BASE
INDEX=1

# Assoc=2
for CACHE_TYPE in LRURP; do # TreePLRURP LIPRP MRURP FIFORP LFURP WeightedLRURP BIPRP RRIPRP BRRIPRP NRURP; do
    echo $INDEX
    ((INDEX++))
    build/X86/gem5.opt  ${TARGET} \
        --cmd=${SRC_DIR} \
        --cpu-type=DerivO3CPU \
        --l1d_size=64kB --l1i_size=64kB --caches \
        --l2_size=2MB --l2cache \
        --sys-clock=1GHz --cpu-clock=1GHz \
        --mem-type=DDR3_1600_8x8 \
        --l1d_repl=${CACHE_TYPE} --l2_repl=${CACHE_TYPE}
    cp m5out/stats.txt ${RESULT_DIR}/${CACHE_TYPE}_2Assoc.txt
done

# Assoc=8
for CACHE_TYPE in LRURP; do # TreePLRURP LIPRP MRURP FIFORP LFURP WeightedLRURP BIPRP RRIPRP BRRIPRP NRURP; do
    echo $INDEX
    ((INDEX++))
    build/X86/gem5.opt ${TARGET} \
        --cmd=${SRC_DIR} \
        --cpu-type=DerivO3CPU \
        --l1d_size=64kB --l1i_size=64kB --l1d_assoc=8 --caches \
        --l2_size=2MB --l2cache \
        --sys-clock=1GHz --cpu-clock=1GHz \
        --mem-type=DDR3_1600_8x8 \
        --l1d_repl=${CACHE_TYPE} --l2_repl=${CACHE_TYPE}
    cp m5out/stats.txt ${RESULT_DIR}/${CACHE_TYPE}_8Assoc.txt
done
