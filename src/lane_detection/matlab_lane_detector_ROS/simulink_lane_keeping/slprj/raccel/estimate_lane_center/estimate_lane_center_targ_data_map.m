  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtP)
    ;%
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% rtP.Constant_Value
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.Constant1_Value
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.Constant10_Value
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.Constant2_Value
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.Constant3_Value
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.Constant4_Value
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtP.Constant5_Value
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtP.Constant6_Value
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtP.Constant7_Value
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtP.Constant8_Value
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtP.Constant9_Value
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 27;
      section.data(27)  = dumData; %prealloc
      
	  ;% rtP.dqp3ofd3v44.Gain_Gain
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.dqp3ofd3v44.Gain1_Gain
	  section.data(2).logicalSrcIdx = 12;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.dqp3ofd3v44.Gain2_Gain
	  section.data(3).logicalSrcIdx = 13;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.dqp3ofd3v44.Gain3_Gain
	  section.data(4).logicalSrcIdx = 14;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.dqp3ofd3v44.Constant_Value
	  section.data(5).logicalSrcIdx = 15;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.dqp3ofd3v44.HalfLaneWidthEstimate_Value
	  section.data(6).logicalSrcIdx = 16;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtP.dqp3ofd3v44.HalfLaneWidthEstimate1_Value
	  section.data(7).logicalSrcIdx = 17;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtP.dqp3ofd3v44.Constant_Value_cijpjtu1ez
	  section.data(8).logicalSrcIdx = 18;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtP.dqp3ofd3v44.HalfLaneWidthEstimate_Value_fad045x02c
	  section.data(9).logicalSrcIdx = 19;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtP.dqp3ofd3v44.HalfLaneWidthEstimate1_Value_kslaxjeuqc
	  section.data(10).logicalSrcIdx = 20;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtP.dqp3ofd3v44.Delay_4_InitialCondition
	  section.data(11).logicalSrcIdx = 21;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtP.dqp3ofd3v44.Delay_3_InitialCondition
	  section.data(12).logicalSrcIdx = 22;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtP.dqp3ofd3v44.Delay_2_InitialCondition
	  section.data(13).logicalSrcIdx = 23;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtP.dqp3ofd3v44.Delay_1_InitialCondition
	  section.data(14).logicalSrcIdx = 24;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtP.dqp3ofd3v44.Merge_1_InitialOutput
	  section.data(15).logicalSrcIdx = 25;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtP.dqp3ofd3v44.Saturation2_UpperSat
	  section.data(16).logicalSrcIdx = 26;
	  section.data(16).dtTransOffset = 15;
	
	  ;% rtP.dqp3ofd3v44.Saturation2_LowerSat
	  section.data(17).logicalSrcIdx = 27;
	  section.data(17).dtTransOffset = 16;
	
	  ;% rtP.dqp3ofd3v44.Merge_2_InitialOutput
	  section.data(18).logicalSrcIdx = 28;
	  section.data(18).dtTransOffset = 17;
	
	  ;% rtP.dqp3ofd3v44.Saturation3_UpperSat
	  section.data(19).logicalSrcIdx = 29;
	  section.data(19).dtTransOffset = 18;
	
	  ;% rtP.dqp3ofd3v44.Saturation3_LowerSat
	  section.data(20).logicalSrcIdx = 30;
	  section.data(20).dtTransOffset = 19;
	
	  ;% rtP.dqp3ofd3v44.Gain_Gain_j0wlcuxobx
	  section.data(21).logicalSrcIdx = 31;
	  section.data(21).dtTransOffset = 20;
	
	  ;% rtP.dqp3ofd3v44.Merge_3_InitialOutput
	  section.data(22).logicalSrcIdx = 32;
	  section.data(22).dtTransOffset = 21;
	
	  ;% rtP.dqp3ofd3v44.Saturation1_UpperSat
	  section.data(23).logicalSrcIdx = 33;
	  section.data(23).dtTransOffset = 22;
	
	  ;% rtP.dqp3ofd3v44.Saturation1_LowerSat
	  section.data(24).logicalSrcIdx = 34;
	  section.data(24).dtTransOffset = 23;
	
	  ;% rtP.dqp3ofd3v44.Merge_4_InitialOutput
	  section.data(25).logicalSrcIdx = 35;
	  section.data(25).dtTransOffset = 24;
	
	  ;% rtP.dqp3ofd3v44.Saturation_UpperSat
	  section.data(26).logicalSrcIdx = 36;
	  section.data(26).dtTransOffset = 25;
	
	  ;% rtP.dqp3ofd3v44.Saturation_LowerSat
	  section.data(27).logicalSrcIdx = 37;
	  section.data(27).dtTransOffset = 26;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtB)
    ;%
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% rtB.dqp3ofd3v44.jjdqfkhq4b
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.dqp3ofd3v44.ns2ckjnnn3
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.dqp3ofd3v44.bhdadxzzzu
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtB.dqp3ofd3v44.gvsf1mrxed
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtB.dqp3ofd3v44.lbbgw3vile
	  section.data(5).logicalSrcIdx = 8;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtB.dqp3ofd3v44.b1op4qu4du
	  section.data(6).logicalSrcIdx = 9;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtB.dqp3ofd3v44.kzoecgydrt
	  section.data(7).logicalSrcIdx = 10;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtB.dqp3ofd3v44.n4ys51bjpp
	  section.data(8).logicalSrcIdx = 11;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtB.dqp3ofd3v44.birpkjwmgk
	  section.data(9).logicalSrcIdx = 12;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtB.dqp3ofd3v44.fhuclp2kjb
	  section.data(10).logicalSrcIdx = 13;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtB.dqp3ofd3v44.gvthkz4uqd
	  section.data(11).logicalSrcIdx = 14;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtB.dqp3ofd3v44.mlekluhdty
	  section.data(12).logicalSrcIdx = 15;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtB.dqp3ofd3v44.gkprg3ghe5
	  section.data(13).logicalSrcIdx = 16;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtB.dqp3ofd3v44.p02tzwdudt
	  section.data(14).logicalSrcIdx = 17;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtB.dqp3ofd3v44.nex4eio1fy
	  section.data(15).logicalSrcIdx = 18;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtB.dqp3ofd3v44.a3kgai34ad
	  section.data(16).logicalSrcIdx = 19;
	  section.data(16).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtDW)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% rtDW.hga0xjow5k.LoggedData
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.m3l1vijl4e.AQHandles
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 4;
	
	  ;% rtDW.dngafahvjf.AQHandles
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 5;
	
	  ;% rtDW.feismhumih.AQHandles
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% rtDW.dqp3ofd3v44.hugbkegs0r
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.dqp3ofd3v44.g5en32gyko
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.dqp3ofd3v44.oogjy025cs
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.dqp3ofd3v44.hv2024htj2
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% rtDW.dqp3ofd3v44.iq513e4hqe
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.dqp3ofd3v44.ilow50ohwe
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.dqp3ofd3v44.gvcnio4hhw
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.dqp3ofd3v44.l4h0aggw4z
	  section.data(4).logicalSrcIdx = 11;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2983954583;
  targMap.checksum1 = 126668576;
  targMap.checksum2 = 2892194270;
  targMap.checksum3 = 4245245358;

