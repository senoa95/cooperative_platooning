%% Calibrator
for i = 1:40
    pause(0.75)
    disp('walk')
    cam_topic = '/usb_cam/image_raw';
    sub = rossubscriber(cam_topic);
    msg = sub.receive;
    frame = msg.readImage;
    fig = imshow(frame);
    file_num = num2str(i);
    file_name = strcat('/home/senoa95/coop_paltoon/src/lane_detection/lane_detection_ros/calibration_files/cal_images/', file_num, '.jpg');
    imwrite(frame, file_name)
end