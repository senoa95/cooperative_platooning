  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
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
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% rtP.left_curvature
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.left_curvature_rate
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.left_lateral_deviation
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.left_relative_yaw_angle
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.left_strength
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.right_curvature
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtP.right_curvature_rate
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtP.right_lateral_deviation
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtP.right_relative_yaw_angle
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtP.right_strength
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtP.Constant_Value
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.Constant11_Value
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.e0dg4qnjc3.Gain_Gain
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 26;
      section.data(26)  = dumData; %prealloc
      
	  ;% rtP.e0dg4qnjc3.Gain_Gain_csudgssrcg
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.e0dg4qnjc3.Gain1_Gain
	  section.data(2).logicalSrcIdx = 14;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.e0dg4qnjc3.Gain2_Gain
	  section.data(3).logicalSrcIdx = 15;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.e0dg4qnjc3.Gain3_Gain
	  section.data(4).logicalSrcIdx = 16;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.e0dg4qnjc3.Constant_Value
	  section.data(5).logicalSrcIdx = 17;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.e0dg4qnjc3.HalfLaneWidthEstimate_Value
	  section.data(6).logicalSrcIdx = 18;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtP.e0dg4qnjc3.HalfLaneWidthEstimate1_Value
	  section.data(7).logicalSrcIdx = 19;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtP.e0dg4qnjc3.Constant_Value_jgqntcaric
	  section.data(8).logicalSrcIdx = 20;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtP.e0dg4qnjc3.HalfLaneWidthEstimate_Value_amvyq0ozrf
	  section.data(9).logicalSrcIdx = 21;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtP.e0dg4qnjc3.HalfLaneWidthEstimate1_Value_kccholnvrj
	  section.data(10).logicalSrcIdx = 22;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtP.e0dg4qnjc3.Delay_4_InitialCondition
	  section.data(11).logicalSrcIdx = 23;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtP.e0dg4qnjc3.Delay_3_InitialCondition
	  section.data(12).logicalSrcIdx = 24;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtP.e0dg4qnjc3.Delay_2_InitialCondition
	  section.data(13).logicalSrcIdx = 25;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtP.e0dg4qnjc3.Delay_1_InitialCondition
	  section.data(14).logicalSrcIdx = 26;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtP.e0dg4qnjc3.Merge_2_InitialOutput
	  section.data(15).logicalSrcIdx = 27;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtP.e0dg4qnjc3.Saturation3_UpperSat
	  section.data(16).logicalSrcIdx = 28;
	  section.data(16).dtTransOffset = 15;
	
	  ;% rtP.e0dg4qnjc3.Saturation3_LowerSat
	  section.data(17).logicalSrcIdx = 29;
	  section.data(17).dtTransOffset = 16;
	
	  ;% rtP.e0dg4qnjc3.Merge_1_InitialOutput
	  section.data(18).logicalSrcIdx = 30;
	  section.data(18).dtTransOffset = 17;
	
	  ;% rtP.e0dg4qnjc3.Saturation2_UpperSat
	  section.data(19).logicalSrcIdx = 31;
	  section.data(19).dtTransOffset = 18;
	
	  ;% rtP.e0dg4qnjc3.Saturation2_LowerSat
	  section.data(20).logicalSrcIdx = 32;
	  section.data(20).dtTransOffset = 19;
	
	  ;% rtP.e0dg4qnjc3.Merge_3_InitialOutput
	  section.data(21).logicalSrcIdx = 33;
	  section.data(21).dtTransOffset = 20;
	
	  ;% rtP.e0dg4qnjc3.Saturation1_UpperSat
	  section.data(22).logicalSrcIdx = 34;
	  section.data(22).dtTransOffset = 21;
	
	  ;% rtP.e0dg4qnjc3.Saturation1_LowerSat
	  section.data(23).logicalSrcIdx = 35;
	  section.data(23).dtTransOffset = 22;
	
	  ;% rtP.e0dg4qnjc3.Merge_4_InitialOutput
	  section.data(24).logicalSrcIdx = 36;
	  section.data(24).dtTransOffset = 23;
	
	  ;% rtP.e0dg4qnjc3.Saturation_UpperSat
	  section.data(25).logicalSrcIdx = 37;
	  section.data(25).dtTransOffset = 24;
	
	  ;% rtP.e0dg4qnjc3.Saturation_LowerSat
	  section.data(26).logicalSrcIdx = 38;
	  section.data(26).dtTransOffset = 25;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtP.k3pph0iicyb.Gain_Gain
	  section.data(1).logicalSrcIdx = 39;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 26;
      section.data(26)  = dumData; %prealloc
      
	  ;% rtP.k3pph0iicyb.Gain_Gain_csudgssrcg
	  section.data(1).logicalSrcIdx = 40;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.k3pph0iicyb.Gain1_Gain
	  section.data(2).logicalSrcIdx = 41;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.k3pph0iicyb.Gain2_Gain
	  section.data(3).logicalSrcIdx = 42;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.k3pph0iicyb.Gain3_Gain
	  section.data(4).logicalSrcIdx = 43;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.k3pph0iicyb.Constant_Value
	  section.data(5).logicalSrcIdx = 44;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.k3pph0iicyb.HalfLaneWidthEstimate_Value
	  section.data(6).logicalSrcIdx = 45;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtP.k3pph0iicyb.HalfLaneWidthEstimate1_Value
	  section.data(7).logicalSrcIdx = 46;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtP.k3pph0iicyb.Constant_Value_jgqntcaric
	  section.data(8).logicalSrcIdx = 47;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtP.k3pph0iicyb.HalfLaneWidthEstimate_Value_amvyq0ozrf
	  section.data(9).logicalSrcIdx = 48;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtP.k3pph0iicyb.HalfLaneWidthEstimate1_Value_kccholnvrj
	  section.data(10).logicalSrcIdx = 49;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtP.k3pph0iicyb.Delay_4_InitialCondition
	  section.data(11).logicalSrcIdx = 50;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtP.k3pph0iicyb.Delay_3_InitialCondition
	  section.data(12).logicalSrcIdx = 51;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtP.k3pph0iicyb.Delay_2_InitialCondition
	  section.data(13).logicalSrcIdx = 52;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtP.k3pph0iicyb.Delay_1_InitialCondition
	  section.data(14).logicalSrcIdx = 53;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtP.k3pph0iicyb.Merge_2_InitialOutput
	  section.data(15).logicalSrcIdx = 54;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtP.k3pph0iicyb.Saturation3_UpperSat
	  section.data(16).logicalSrcIdx = 55;
	  section.data(16).dtTransOffset = 15;
	
	  ;% rtP.k3pph0iicyb.Saturation3_LowerSat
	  section.data(17).logicalSrcIdx = 56;
	  section.data(17).dtTransOffset = 16;
	
	  ;% rtP.k3pph0iicyb.Merge_1_InitialOutput
	  section.data(18).logicalSrcIdx = 57;
	  section.data(18).dtTransOffset = 17;
	
	  ;% rtP.k3pph0iicyb.Saturation2_UpperSat
	  section.data(19).logicalSrcIdx = 58;
	  section.data(19).dtTransOffset = 18;
	
	  ;% rtP.k3pph0iicyb.Saturation2_LowerSat
	  section.data(20).logicalSrcIdx = 59;
	  section.data(20).dtTransOffset = 19;
	
	  ;% rtP.k3pph0iicyb.Merge_3_InitialOutput
	  section.data(21).logicalSrcIdx = 60;
	  section.data(21).dtTransOffset = 20;
	
	  ;% rtP.k3pph0iicyb.Saturation1_UpperSat
	  section.data(22).logicalSrcIdx = 61;
	  section.data(22).dtTransOffset = 21;
	
	  ;% rtP.k3pph0iicyb.Saturation1_LowerSat
	  section.data(23).logicalSrcIdx = 62;
	  section.data(23).dtTransOffset = 22;
	
	  ;% rtP.k3pph0iicyb.Merge_4_InitialOutput
	  section.data(24).logicalSrcIdx = 63;
	  section.data(24).dtTransOffset = 23;
	
	  ;% rtP.k3pph0iicyb.Saturation_UpperSat
	  section.data(25).logicalSrcIdx = 64;
	  section.data(25).dtTransOffset = 24;
	
	  ;% rtP.k3pph0iicyb.Saturation_LowerSat
	  section.data(26).logicalSrcIdx = 65;
	  section.data(26).dtTransOffset = 25;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
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
    nTotSects     = 4;
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
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.e0dg4qnjc3.icvqtrbbcd
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% rtB.e0dg4qnjc3.dlphfoumb0
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.e0dg4qnjc3.dkaupoobjr
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.e0dg4qnjc3.j0y3qvbbhb
	  section.data(3).logicalSrcIdx = 7;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtB.e0dg4qnjc3.g34esawosi
	  section.data(4).logicalSrcIdx = 8;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtB.e0dg4qnjc3.oqjwvlopf5
	  section.data(5).logicalSrcIdx = 9;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtB.e0dg4qnjc3.kdicdcckls
	  section.data(6).logicalSrcIdx = 10;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtB.e0dg4qnjc3.mvxqr2bcws
	  section.data(7).logicalSrcIdx = 11;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtB.e0dg4qnjc3.e53ulgorx1
	  section.data(8).logicalSrcIdx = 12;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtB.e0dg4qnjc3.fh2jemzwct
	  section.data(9).logicalSrcIdx = 13;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtB.e0dg4qnjc3.oc05twylps
	  section.data(10).logicalSrcIdx = 14;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtB.e0dg4qnjc3.ggudjvgpuu
	  section.data(11).logicalSrcIdx = 15;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtB.e0dg4qnjc3.jev0d0au1k
	  section.data(12).logicalSrcIdx = 16;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtB.e0dg4qnjc3.pyt3nna2lj
	  section.data(13).logicalSrcIdx = 17;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtB.e0dg4qnjc3.ov5lcbuchn
	  section.data(14).logicalSrcIdx = 18;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtB.e0dg4qnjc3.c0xy4zpqv1
	  section.data(15).logicalSrcIdx = 19;
	  section.data(15).dtTransOffset = 14;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.k3pph0iicyb.icvqtrbbcd
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% rtB.k3pph0iicyb.dlphfoumb0
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.k3pph0iicyb.dkaupoobjr
	  section.data(2).logicalSrcIdx = 26;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.k3pph0iicyb.j0y3qvbbhb
	  section.data(3).logicalSrcIdx = 27;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtB.k3pph0iicyb.g34esawosi
	  section.data(4).logicalSrcIdx = 28;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtB.k3pph0iicyb.oqjwvlopf5
	  section.data(5).logicalSrcIdx = 29;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtB.k3pph0iicyb.kdicdcckls
	  section.data(6).logicalSrcIdx = 30;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtB.k3pph0iicyb.mvxqr2bcws
	  section.data(7).logicalSrcIdx = 31;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtB.k3pph0iicyb.e53ulgorx1
	  section.data(8).logicalSrcIdx = 32;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtB.k3pph0iicyb.fh2jemzwct
	  section.data(9).logicalSrcIdx = 33;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtB.k3pph0iicyb.oc05twylps
	  section.data(10).logicalSrcIdx = 34;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtB.k3pph0iicyb.ggudjvgpuu
	  section.data(11).logicalSrcIdx = 35;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtB.k3pph0iicyb.jev0d0au1k
	  section.data(12).logicalSrcIdx = 36;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtB.k3pph0iicyb.pyt3nna2lj
	  section.data(13).logicalSrcIdx = 37;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtB.k3pph0iicyb.ov5lcbuchn
	  section.data(14).logicalSrcIdx = 38;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtB.k3pph0iicyb.c0xy4zpqv1
	  section.data(15).logicalSrcIdx = 39;
	  section.data(15).dtTransOffset = 14;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
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
    nTotSects     = 7;
    sectIdxOffset = 4;
    
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
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% rtDW.m3l1vijl4e.AQHandles
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.i10vows2kx.LoggedData
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.dngafahvjf.AQHandles
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.feismhumih.AQHandles
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.kovwqq2md4.LoggedData
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.g2ldytnxfq.LoggedData
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.ok2p2lv0ek.LoggedData
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.a3kpjsykfj.AQHandles
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtDW.dnvh1kcj2i.LoggedData
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtDW.jshekjjwkp.AQHandles
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtDW.fg10l0wasa.AQHandles
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtDW.panzj3fxix.LoggedData
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtDW.nutfnhr4zj.LoggedData
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtDW.bmwwkwthwc.LoggedData
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.e0dg4qnjc3.bv5olnepf0.LoggedData
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% rtDW.e0dg4qnjc3.eckz3pxwzc
	  section.data(1).logicalSrcIdx = 15;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.e0dg4qnjc3.f5zwivgby1
	  section.data(2).logicalSrcIdx = 16;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.e0dg4qnjc3.cvvezosg3d
	  section.data(3).logicalSrcIdx = 17;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.e0dg4qnjc3.o03k3dg52b
	  section.data(4).logicalSrcIdx = 18;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% rtDW.e0dg4qnjc3.gsiekacha1
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.e0dg4qnjc3.o40mjycyzi
	  section.data(2).logicalSrcIdx = 20;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.e0dg4qnjc3.gppbpgjejo
	  section.data(3).logicalSrcIdx = 21;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.e0dg4qnjc3.mwbiwkoruj
	  section.data(4).logicalSrcIdx = 22;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.k3pph0iicyb.bv5olnepf0.LoggedData
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% rtDW.k3pph0iicyb.eckz3pxwzc
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.k3pph0iicyb.f5zwivgby1
	  section.data(2).logicalSrcIdx = 25;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.k3pph0iicyb.cvvezosg3d
	  section.data(3).logicalSrcIdx = 26;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.k3pph0iicyb.o03k3dg52b
	  section.data(4).logicalSrcIdx = 27;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% rtDW.k3pph0iicyb.gsiekacha1
	  section.data(1).logicalSrcIdx = 28;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.k3pph0iicyb.o40mjycyzi
	  section.data(2).logicalSrcIdx = 29;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.k3pph0iicyb.gppbpgjejo
	  section.data(3).logicalSrcIdx = 30;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.k3pph0iicyb.mwbiwkoruj
	  section.data(4).logicalSrcIdx = 31;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
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


  targMap.checksum0 = 1266430929;
  targMap.checksum1 = 2926641344;
  targMap.checksum2 = 2919994738;
  targMap.checksum3 = 3380208096;

