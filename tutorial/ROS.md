Raspberry Pi 2 上移植ROS
====

#### 1.安装过程
* 前期准备  
   * sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu wheezy main" > /etc/apt/sources.list.d/ros-latest.list'
   * wget https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -O - | sudo apt-key add -
   * sudo apt-get update
   * sudo apt-get upgrade
   * sudo apt-get install python-setuptools python-pip python-yaml python-argparse python-distribute python-docutils python-dateutil python-setuptools python-six
   * sudo pip install rosdep rosinstall_generator wstool rosinstall
   * sudo rosdep init
   * rosdep update       
  
  ----
* 安装过程
   * mkdir ~/ros_catkin_ws & cd ~/ros_catkin_ws
   * rosinstall_generator desktop --rosdistro indigo --deps --wet-only --exclude roslisp --tar > indigo-desktop-wet.rosinstall
   * wstool init src indigo-desktop-wet.rosinstall        
          
          
  -----   
* 解决依赖     
  * mkdir ~/ros_catkin_ws/external_src    
  * sudo apt-get install checkinstall cmake   
  * sudo sh -c 'echo "deb-src http://mirrordirector.raspbian.org/raspbian/ testing main contrib non-free rpi" >> /etc/apt/sources.list'
  * sudo apt-get update
  * libconsole-bridge-dev     
       * cd ~/ros_catkin_ws/external_src
       * sudo apt-get build-dep console-bridge
       * apt-get source -b console-bridge
       * sudo dpkg -i libconsole-bridge0.2_*.deb libconsole-bridge-dev_*.deb       
  * liblz4-dev
  * liburdfdom-headers-dev
  * liburdfdom-dev
  * collada-dom-dev     
  * cd ~/ros_catkin_ws
  * rosdep install --from-paths src --ignore-src --rosdistro indigo -y -r --os=debian:wheezy
  * sudo ./src/catkin/bin/catkin_make_isolated --install -DCMAKE_BUILD_TYPE=Release --install-space /opt/ros/indigo
       
         
  ----
#### 2. 问题及解决方案      

    在树莓派2上安装ROS中间很容易出现各种问题，我遇到的几个主要问题如下：   
    1. 官网教程安装liblz4-dev 过程中apt-get source -b lz4指令出现问题，可采用wget的方式解决；
    2.  安装liburdfdom-headers-dev、liburdfdom-dev、collada-dom-dev checkinstall时需要更改其名字，选择2，分别更新名称为liburdfdom-headers-dev、liburdfdom-dev、collada-dom-dev  
    3.  module named pkg_resources   
       解决：wget https://bitbucket.org/pypa/setuptools/raw/bootstrap/ez_setup.py -O - | python 
    4. 编译安装时会出现collada_urdf等包安装问题，将包从该目录 ~/ros_catkin_ws/src/robot_model 目录中移出，这一点有些折腾  
    5.  安装到169包/184时，会出现rviz安装包问题，无法安装，而有人给出解决方案：.../ros_catkin_ws/build_isolated/rviz/make -j2，     
    但是实际中依然无法从根本上解决该问题。事实上，该包可以不用安装，当你需要使用该包时在折腾吧，不然太浪费时间了。
    
######. 参考资源
* ROS官网[安装教程](http://wiki.ros.org/ROSberryPi/Installing%20ROS%20Indigo%20on%20Raspberry%20Pi)     
* 博客教程[安装指导](http://blog.csdn.net/crazyquhezheng/article/details/43413231)    
