#! /bin/bash

[ -e "$BIN_DATA_PATH" ] || BIN_DATA_PATH=/data2/slava77/samples/2021/11834.0_TTbar_14TeV+2021/
fin=${BIN_DATA_PATH}/AVE_70_BX01_25ns/memoryFile.fv6.default.211008-c6b7c67.bin

runValidation()
{
    for sV in "sim --cmssw-simseeds" "see --cmssw-stdseeds"; do echo $sV | while read -r sN sO; do
	    if [ "${1}" == "1" ]; then
		sO="--cmssw-n2seeds"
	    fi
            for bV in "BH bh" "STD std" "CE ce"; do echo $bV | while read -r bN bO; do
		    oBase=${base}_${sN}_${bN}
		    nTH=8
		    echo "${oBase}: validation [nTH:${nTH}, nVU:8]"
		    ./mkFit/mkFit --sim-val --input-file ${fin} --build-${bO} ${sO} --num-thr ${nTH} >& log_${oBase}_NVU8int_NTH${nTH}_val.txt
		    mv valtree.root valtree_${oBase}.root
                done
            done
        done
    done
        
    for opt in sim see
    do
        oBase=${base}_${opt}
        for build in BH STD CE
        do
	    root -b -q -l plotting/runValidation.C+\(\"_${oBase}_${build}\"\)
        done
        root -b -q -l plotting/makeValidation.C+\(\"${oBase}\"\)
    done
}

#cleanup first
make clean
make distclean
make -j 12 WITH_ROOT:=1

export base=SNB_CMSSW_PU70_clean
echo Run default build with base = ${base}
runValidation 0

export base=SNB_CMSSW_PU70_clean_cleanSeed
echo Run CLEAN_SEEDS with base = ${base}
runValidation 1

make distclean

unset base
