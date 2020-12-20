%% Calibrator
for i = 1:40
    pause(0.5)
    cam_topic = '/usb_cam/image_raw';
    sub = rossubscriber(cam_topic);
    msg = sub.receive;
    frame = msg.readImage;
    fig = imshow(frame);
    file_num = num2str(i);
    file_name = strcat('/home/base/Desktop/image_', file_num, '.jpg')
    imwrite(frame, file_name)
end