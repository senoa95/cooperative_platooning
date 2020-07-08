classdef CustomMsgConsts
    %CustomMsgConsts This class stores all message types
    %   The message types are constant properties, which in turn resolve
    %   to the strings of the actual types.
    
    %   Copyright 2014-2020 The MathWorks, Inc.
    
    properties (Constant)
        novatel_gps_msgs_ClockSteering = 'novatel_gps_msgs/ClockSteering'
        novatel_gps_msgs_Gpgga = 'novatel_gps_msgs/Gpgga'
        novatel_gps_msgs_Gpgsa = 'novatel_gps_msgs/Gpgsa'
        novatel_gps_msgs_Gpgsv = 'novatel_gps_msgs/Gpgsv'
        novatel_gps_msgs_Gphdt = 'novatel_gps_msgs/Gphdt'
        novatel_gps_msgs_Gprmc = 'novatel_gps_msgs/Gprmc'
        novatel_gps_msgs_Inscov = 'novatel_gps_msgs/Inscov'
        novatel_gps_msgs_Inspva = 'novatel_gps_msgs/Inspva'
        novatel_gps_msgs_Inspvax = 'novatel_gps_msgs/Inspvax'
        novatel_gps_msgs_Insstdev = 'novatel_gps_msgs/Insstdev'
        novatel_gps_msgs_NovatelCorrectedImuData = 'novatel_gps_msgs/NovatelCorrectedImuData'
        novatel_gps_msgs_NovatelDualAntennaHeading = 'novatel_gps_msgs/NovatelDualAntennaHeading'
        novatel_gps_msgs_NovatelExtendedSolutionStatus = 'novatel_gps_msgs/NovatelExtendedSolutionStatus'
        novatel_gps_msgs_NovatelHeading2 = 'novatel_gps_msgs/NovatelHeading2'
        novatel_gps_msgs_NovatelMessageHeader = 'novatel_gps_msgs/NovatelMessageHeader'
        novatel_gps_msgs_NovatelPosition = 'novatel_gps_msgs/NovatelPosition'
        novatel_gps_msgs_NovatelPsrdop2 = 'novatel_gps_msgs/NovatelPsrdop2'
        novatel_gps_msgs_NovatelPsrdop2System = 'novatel_gps_msgs/NovatelPsrdop2System'
        novatel_gps_msgs_NovatelReceiverStatus = 'novatel_gps_msgs/NovatelReceiverStatus'
        novatel_gps_msgs_NovatelSignalMask = 'novatel_gps_msgs/NovatelSignalMask'
        novatel_gps_msgs_NovatelUtmPosition = 'novatel_gps_msgs/NovatelUtmPosition'
        novatel_gps_msgs_NovatelVelocity = 'novatel_gps_msgs/NovatelVelocity'
        novatel_gps_msgs_NovatelXYZ = 'novatel_gps_msgs/NovatelXYZ'
        novatel_gps_msgs_Range = 'novatel_gps_msgs/Range'
        novatel_gps_msgs_RangeInformation = 'novatel_gps_msgs/RangeInformation'
        novatel_gps_msgs_Satellite = 'novatel_gps_msgs/Satellite'
        novatel_gps_msgs_Time = 'novatel_gps_msgs/Time'
        novatel_gps_msgs_Trackstat = 'novatel_gps_msgs/Trackstat'
        novatel_gps_msgs_TrackstatChannel = 'novatel_gps_msgs/TrackstatChannel'
    end
    
    methods (Static, Hidden)
        function messageList = getMessageList
            %getMessageList Generate a cell array with all message types.
            %   The list will be sorted alphabetically.
            
            persistent msgList
            if isempty(msgList)
                msgList = cell(29, 1);
                msgList{1} = 'novatel_gps_msgs/ClockSteering';
                msgList{2} = 'novatel_gps_msgs/Gpgga';
                msgList{3} = 'novatel_gps_msgs/Gpgsa';
                msgList{4} = 'novatel_gps_msgs/Gpgsv';
                msgList{5} = 'novatel_gps_msgs/Gphdt';
                msgList{6} = 'novatel_gps_msgs/Gprmc';
                msgList{7} = 'novatel_gps_msgs/Inscov';
                msgList{8} = 'novatel_gps_msgs/Inspva';
                msgList{9} = 'novatel_gps_msgs/Inspvax';
                msgList{10} = 'novatel_gps_msgs/Insstdev';
                msgList{11} = 'novatel_gps_msgs/NovatelCorrectedImuData';
                msgList{12} = 'novatel_gps_msgs/NovatelDualAntennaHeading';
                msgList{13} = 'novatel_gps_msgs/NovatelExtendedSolutionStatus';
                msgList{14} = 'novatel_gps_msgs/NovatelHeading2';
                msgList{15} = 'novatel_gps_msgs/NovatelMessageHeader';
                msgList{16} = 'novatel_gps_msgs/NovatelPosition';
                msgList{17} = 'novatel_gps_msgs/NovatelPsrdop2';
                msgList{18} = 'novatel_gps_msgs/NovatelPsrdop2System';
                msgList{19} = 'novatel_gps_msgs/NovatelReceiverStatus';
                msgList{20} = 'novatel_gps_msgs/NovatelSignalMask';
                msgList{21} = 'novatel_gps_msgs/NovatelUtmPosition';
                msgList{22} = 'novatel_gps_msgs/NovatelVelocity';
                msgList{23} = 'novatel_gps_msgs/NovatelXYZ';
                msgList{24} = 'novatel_gps_msgs/Range';
                msgList{25} = 'novatel_gps_msgs/RangeInformation';
                msgList{26} = 'novatel_gps_msgs/Satellite';
                msgList{27} = 'novatel_gps_msgs/Time';
                msgList{28} = 'novatel_gps_msgs/Trackstat';
                msgList{29} = 'novatel_gps_msgs/TrackstatChannel';
            end
            
            messageList = msgList;
        end
        
        function serviceList = getServiceList
            %getServiceList Generate a cell array with all service types.
            %   The list will be sorted alphabetically.
            
            persistent svcList
            if isempty(svcList)
                svcList = cell(0, 1);
            end
            
            % The message list was already sorted, so don't need to sort
            % again.
            serviceList = svcList;
        end
        
        function actionList = getActionList
            %getActionList Generate a cell array with all action types.
            %   The list will be sorted alphabetically.
            
            persistent actList
            if isempty(actList)
                actList = cell(0, 1);
            end
            
            % The message list was already sorted, so don't need to sort
            % again.
            actionList = actList;
        end
    end
end
