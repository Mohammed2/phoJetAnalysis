#!/bin/bash

inputPath="/hdfs/store/user/varuns/NTuples/MC/MC2017_12Apr2018_94X/QCD/QCD_HT100To200"
outputPath="/hdfs/store/user/varuns/NTuples/MC/MC2017_12Apr2018_94X/QCD/qcd_HT100To200"

fileName="MC_QCD_HT100-200_"

checkNsubDir=`ls $inputPath | wc -l`

outFileIndex=0;

for (( iDir = 0; iDir < $checkNsubDir; iDir++)); do

  filesInFolder=`ls $inputPath/000$iDir/*.root | wc -l`
  fileToHadd=5;			       
  nOutFiles=$(($filesInFolder/$fileToHadd))
  remainder=$(($filesInFolder%$fileToHadd))

  for (( i = 0; i < $nOutFiles; i++)); do
    if [ $iDir -eq 0 ]; then
      outFileIndex=$(( $outFileIndex+1 ))
      one=$(( ($i*$fileToHadd)+1 ))      
      two=$(( ($i*$fileToHadd)+2 ))      
      three=$(( ($i*$fileToHadd)+3 ))    
      four=$(( ($i*$fileToHadd)+4 )) 
      five=$(( ($i*$fileToHadd)+5 ))
    else
      outFileIndex=$(( $outFileIndex+1 ))
      one=$(( (1000*$iDir)+($i*$fileToHadd)+0 ))
      two=$(( (1000*$iDir)+($i*$fileToHadd)+1 ))
      three=$(( (1000*$iDir)+($i*$fileToHadd)+2 ))
      four=$(( (1000*$iDir)+($i*$fileToHadd)+3 ))
      five=$(( (1000*$iDir)+($i*$fileToHadd)+4 ))
    fi
 
    echo "hadd $fileName$outFileIndex.root $fileName$one.root $fileName$two.root $fileName$three.root $fileName$four.root $fileName$five.root"
  done

  if [ $remainder -eq 1 ]; then
    outFileIndex=$(( $outFileIndex+1 ))
    one=$(( ($five)+1 ))
    echo "hadd $fileName$outFileIndex.root $fileName$one.root"
  elif [ $remainder -eq 2 ]; then
    outFileIndex=$(( $outFileIndex+1 ))
    one=$(( ($five)+1 ))
    two=$(( ($five)+2 ))
    echo "hadd $fileName$outFileIndex.root $fileName$one.root $fileName$two.root"
  elif [ $remainder -eq 3 ]; then
    outFileIndex=$(( $outFileIndex+1 ))
    one=$(( ($five)+1 ))
    two=$(( ($five)+2 ))
    three=$(( ($five)+3 ))
    echo "hadd $fileName$outFileIndex.root $fileName$one.root $fileName$two.root $fileName$three.root"
  elif [ $remainder -eq 4 ]; then
    outFileIndex=$(( $outFileIndex+1 ))
    one=$(( ($five)+1 ))
    two=$(( ($five)+2 ))
    three=$(( ($five)+3 ))
    four=$(( ($five)+4 ))
    echo "hadd $fileName$outFileIndex.root $fileName$one.root $fileName$two.root $fileName$three.root $fileName$four.root"
 fi
done
