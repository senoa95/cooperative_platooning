roboteq
=======

ROS driver for serial Roboteq motor controllers. This driver is suitable for use with Roboteq's
Advanced Digital Motor Controllers, as described in [this document][1]. Devices include:

This fork is specfically design to work with the Virginia Tech Turtle Platform with the HBL 2350 drivers.

```roslaunch roboteq_driver example.launch``` Will start the motor controller node with a left and right channel 

The node works by downloading a MicroBasic script to the driver, which then publishes ASCII sentences at 10Hz and 50Hz with the data corresponding to the Status and per-channel Feedback messages published by the driver.

[1]: https://www.roboteq.com/index.php/docman/motor-controllers-documents-and-files/documentation/user-manual/272-roboteq-controllers-user-manual-v17/file
