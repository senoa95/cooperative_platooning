# /bin/bash
roscore
rosparam load ~/coop_paltoon/src/lane_keeping/src/path_follower/launch/params_temp
cd ~/V-REP_PRO_EDU_V3_6_2_Ubuntu16_04
./vrep.sh
