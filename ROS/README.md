## ROS基础

### 1. 基础命令

ROS命令工具的的命名方式：

- rospack = ros + pack(age)
- roscd = ros + cd
- rosls = ros + ls

这种命名方式在许多ROS命令工具中都会用到

**快速了解文件系统概念**

- **Packages:** 软件包，是ROS应用程序代码的组织单元，每个软件包都可以包含程序库、可执行文件、脚本或者其它手动创建的东西。
- **Manifest (package.xml):** 清单，是对于'软件包'相关信息的描述,用于定义软件包相关元信息之间的依赖关系，这些信息包括版本、维护者和许可协议等

1. [rospack](http://wiki.ros.org/rospack)允许你获取软件包的有关信息。在本教程中，我们只涉及到`rospack`中`find`参数选项，该选项可以返回软件包的路径信息。

   用法：

   ```
   # rospack find [包名称]
   ```

   示例：

   ```
   $ rospack find roscpp
   ```

2. #### 用 roscd

   `roscd`是[rosbash](http://wiki.ros.org/rosbash)命令集中的一部分，它允许你直接切换([cd](http://ss64.com/bash/cd.html))工作目录到某个软件包或者软件包集当中。

   用法：

   ```
   # roscd [本地包名称[/子目录]]
   ```

   示例：

   ```
   $ roscd roscpp
   ```

**注意**，就像ROS中的其它工具一样，[roscd](http://wiki.ros.org/roscd)只能切换到那些路径已经包含在[ROS_PACKAGE_PATH](http://wiki.ros.org/ROS/EnvironmentVariables#ROS_PACKAGE_PATH)环境变量中的软件包，要查看[ROS_PACKAGE_PATH](http://wiki.ros.org/ROS/EnvironmentVariables#ROS_PACKAGE_PATH)中包含的路径可以输入：

```
$ echo $ROS_PACKAGE_PATH
```

你的[ROS_PACKAGE_PATH](http://wiki.ros.org/ROS/EnvironmentVariables#ROS_PACKAGE_PATH)环境变量应该包含那些保存有ROS软件包的路径，并且每个路径之间用冒号分隔开来。一个典型的[ROS_PACKAGE_PATH](http://wiki.ros.org/ROS/EnvironmentVariables#ROS_PACKAGE_PATH)环境变量如下

```
/opt/ros/groovy/base/install/share:/opt/ros/groovy/base/install/stacks
```

跟其他路径环境变量类似，你可以在[ROS_PACKAGE_PATH](http://wiki.ros.org/ROS/EnvironmentVariables#ROS_PACKAGE_PATH)中添加更多其它路径，每条路径使用冒号':'分隔。

子目录

3. #### 使用 rosls

   [rosls](http://wiki.ros.org/rosbash#rosls)是[rosbash](http://wiki.ros.org/rosbash)命令集中的一部分，它允许你直接按软件包的名称而不是绝对路径执行[ls](http://ss64.com/bash/ls.html)命令（罗列目录）。

   用法：

   ```
   # rosls [本地包名称[/子目录]]
   ```

   示例：

   ```
   $ rosls roscpp_tutorials
   ```

4. #### Tab 自动完成输入

   当要输入一个完整的软件包名称时会变得比较繁琐。在之前的例子中`roscpp tutorials`是个相当长的名称，幸运的是，一些ROS工具支持[TAB 自动完成输入](http://en.wikipedia.org/wiki/Command_line_completion)的功能。

### 2. 创建ROS程序包

#### 1. 一个catkin程序包由什么组成?

一个程序包要想称为catkin程序包必须符合以下要求：

- 该程序包必须包含[catkin compliant package.xml](http://wiki.ros.org/catkin/package.xml)文件
  - 这个package.xml文件提供有关程序包的元信息。
- 程序包必须包含一个[catkin 版本的CMakeLists.txt](http://wiki.ros.org/catkin/CMakeLists.txt)文件，而[Catkin metapackages](http://wiki.ros.org/catkin/package.xml#Metapackages)中必须包含一个对CMakeList.txt文件的引用。
- 每个目录下只能有一个程序包。
  - 这意味着在同一个目录下不能有嵌套的或者多个程序包存在。

最简单的程序包也许看起来就像这样：

```
my_package/
  CMakeLists.txt
  package.xml
```

#### 2. 在catkin工作空间中的程序包

开发catkin程序包的一个推荐方法是使用[catkin工作空间](http://wiki.ros.org/catkin/workspaces)，但是你也可以[单独开发(standalone)](http://wiki.ros.org/catkin/build_standalone)catkin 软件包。一个简单的工作空间也许看起来像这样：

```
workspace_folder/        -- WORKSPACE
  src/                   -- SOURCE SPACE
    CMakeLists.txt       -- 'Toplevel' CMake file, provided by catkin
    package_1/
      CMakeLists.txt     -- CMakeLists.txt file for package_1
      package.xml        -- Package manifest for package_1
    ...
    package_n/
      CMakeLists.txt     -- CMakeLists.txt file for package_n
      package.xml        -- Package manifest for package_n
```

#### 3. 创建一个catkin程序包

首先，创建catkin工作空间，you have [installed catkin](http://www.ros.org/wiki/catkin#Installing_catkin) and sourced your environment

```
$ mkdir -p ~/catkin_ws/src
$ cd ~/catkin_ws/
$ catkin_make
```

因为，carkin_make命令需要在catkin workspace中工作，所以，上面就是创建了空间。‘src’中包含了CMakeList.txt文件，同时，还有‘build’和‘devel’文件夹，并且，需要写入bash文件，方便后面添加到环境变量

```
$ source devel/setup.bash
```

```
$ echo $ROS_PACKAGE_PATH
/home/youruser/catkin_ws/src:/opt/ros/kinetic/share
```



首先切换到之前通过[创建catkin工作空间教程](http://wiki.ros.org/catkin/Tutorials/create_a_workspace)创建的catkin工作空间中的src目录下：

```
# You should have created this in the Creating a Workspace Tutorial
$ cd ~/catkin_ws/src
```

现在使用`catkin_create_pkg`命令来创建一个名为'beginner_tutorials'的新程序包，这个程序包依赖于std_msgs、roscpp和rospy：

```
$ catkin_create_pkg beginner_tutorials std_msgs rospy roscpp
```

```
$ cd ..
$ source devel/setup.bash
```

这将会创建一个名为`beginner_tutorials`的文件夹，这个文件夹里面包含一个[package.xml](http://wiki.ros.org/catkin/package.xml)文件和一个[CMakeLists.txt](http://wiki.ros.org/catkin/CMakeLists.txt)文件，这两个文件都已经自动包含了部分你在执行`catkin_create_pkg`命令时提供的信息。

`catkin_create_pkg`命令会要求你输入`package_name`，如果有需要你还可以在后面添加一些需要依赖的其它程序包：

```
# This is an example, do not try to run this
# catkin_create_pkg <package_name> [depend1] [depend2] [depend3]
```

`catkin_create_pkg`命令也有更多的高级功能，这些功能在[catkin/commands/catkin_create_pkg](http://wiki.ros.org/catkin/commands/catkin_create_pkg)中有描述。

#### 4. 程序包依赖关系

**一级依赖**

```
$ rospack depends1 beginner_tutorials 
```

```
std_msgs
rospy
roscpp
```

就像你看到的，`rospack`列出了在运行`catkin_create_pkg`命令时作为参数的依赖包，这些依赖包随后保存在**package.xml**文件中。

```
$ roscd beginner_tutorials
$ cat package.xml
```

**间接依赖**

在很多情况中，一个依赖包还会有它自己的依赖包，比如，`rospy`还有其它依赖包。

```
$ rospack depends1 rospy
```

```
genpy
rosgraph
rosgraph_msgs
roslib
std_msgs
```

一个程序包还可以有好几个间接的依赖包，幸运的是使用`rospack`可以递归检测出所有的依赖包。

```
$ rospack depends beginner_tutorials
```

### 编译ROS程序包

#### 编译程序包

一旦安装了所需的系统依赖项，我们就可以开始编译刚才创建的程序包了。

**注意:** 如果你是通过`apt`或者其它软件包管理工具来安装ROS的，那么系统已经默认安装好所有依赖项。

记得事先source你的环境配置(setup)文件，在Ubuntu中的操作指令如下：

```
$ source /opt/ros/groovy/setup.bash
#或者是indigo，看版本
$ source /opt/ros/indigo/setup.bash
```

#### 开始编译你的程序包

对于正要马上编译自己代码的读者，请同时看一下后面的[(C++)](http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28c%2B%2B%29)/[(Python)](http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28python%29)教程，因为你可能需要修改`CMakeLists.txt`文件。

按照之前的[创建一个ROS程序包](http://wiki.ros.org/cn/ROS/Tutorials/CreatingPackage)教程，你应该已经创建好了一个[catkin 工作空间](http://wiki.ros.org/catkin/Tutorials/create_a_workspace) 和一个名为`beginner_tutorials`的catkin 程序包。现在切换到catkin workspace 并查看`src`文件夹：

```
$ cd ~/catkin_ws/
$ ls src   `ls是显示文件夹里面的内容`
```

```
beginner_tutorials/  CMakeLists.txt
```

你可以看到一个名为`beginner_tutorials`的文件夹，这就是你在之前的 [catkin_create_pkg](http://wiki.ros.org/catkin/commands/catkin_create_pkg)教程里创建的。现在我们可以使用[catkin_make](http://wiki.ros.org/catkin/commands/catkin_make)来编译它了:

```
$ catkin_make
```

你可以看到很多`cmake` 和 `make` 输出的信息：

[catkin_make](http://wiki.ros.org/catkin/commands/catkin_make)首先输出它所使用到的每个**空间**所在的路径。更多关于**空间**的信息，请参考[REP128](http://ros.org/reps/rep-0128.html)和[catkin/workspaces](http://wiki.ros.org/catkin/workspaces)。需要注意的是由于这些空间存在默认配置的原因，有几个文件夹已经在catkin工作空间自动生成了，使用`ls`查看:

```
$ ls
```

```
build
devel
src
```

`build` 目录是[build space](http://wiki.ros.org/catkin/workspaces#Build_Space)的默认所在位置，同时`cmake` 和 `make`也是在这里被调用来配置并编译你的程序包。`devel` 目录是[devel space](http://wiki.ros.org/catkin/workspaces#Development_.28Devel.29_Space)的默认所在位置, 同时也是在你安装程序包之前存放可执行文件和库文件的地方。

### 理解 ROS节点

**Description:** 本教程主要介绍 ROS 图（graph）概念 并讨论[roscore](http://wiki.ros.org/roscore)、[rosnode](http://wiki.ros.org/rosnode)和 [rosrun](http://wiki.ros.org/rosrun) 命令行工具的使用。

#### 0. 图概念概述

- [Nodes](http://wiki.ros.org/Nodes):节点,一个节点即为一个可执行文件，它可以通过ROS与其它节点进行通信。
- [Messages](http://wiki.ros.org/Messages):消息，消息是一种ROS数据类型，用于订阅或发布到一个话题。
- [Topics](http://wiki.ros.org/Topics):话题,节点可以发布消息到话题，也可以订阅话题以接收消息。
- [Master](http://wiki.ros.org/Master):节点管理器，ROS名称服务 (比如帮助节点找到彼此)。
- [rosout](http://wiki.ros.org/rosout): ROS中相当于stdout/stderr。
- [roscore](http://wiki.ros.org/roscore): 主机+ rosout + 参数服务器 (参数服务器会在后面介绍)。

#### 1. 节点

一个节点其实只不过是ROS程序包中的一个可执行文件。ROS节点可以使用ROS客户库与其他节点通信。节点可以发布或接收一个话题。节点也可以提供或使用某种服务。

（节点是ros中非常重要的一个概念，为了帮助初学者理解这个概念，这里举一个通俗的例子：

例如，咱们有一个机器人，和一个遥控器，那么这个机器人和遥控器开始工作后，就是两个节点。遥控器起到了下达指 令的作用；机器人负责监听遥控器下达的指令，完成相应动作。从这里我们可以看出，节点是一个能执行特定工作任 务的工作单元，并且能够相互通信，从而实现一个机器人系统整体的功能。在这里我们把遥控器和机器人简单定义为两个节点，实际上在机器人中根据控制器、传感器、执行机构等不同组成模块，还可以将其进一步细分为更多的节点，这个是根据用户编写的程序来定义的。）

#### 2. 客户端库

ROS客户端库允许使用不同编程语言编写的节点之间互相通信:

- rospy = python 客户端库
- roscpp = c++ 客户端库

#### 3. roscore

`roscore` 是你在运行所有ROS程序前首先要运行的命令。

请运行:

```
$ roscore
```

如果 `roscore` 运行后无法正常初始化，很有可能是存在网络配置问题。参见

[网络设置——单机设置](http://www.ros.org/wiki/ROS/NetworkSetup#Single_machine_configuration)

如果 `roscore` 不能初始化并提示缺少权限，这可能是因为`~/.ros`文件夹

归属于root用户（只有root用户才能访问），修改该文件夹的用户归属关系：

```
$ sudo chown -R <your_username> ~/.ros
```

#### 4. 使用rosnode

打开一个**新的终端**, 可以使用 **rosnode** 像运行 `roscore` 一样看看在

运行什么...

**注意:** 当打开一个新的终端时，你的运行环境会复位，同时你的`~/.bashrc`

文件会复原。如果你在运行类似于`rosnode`的指令时出现一些问题，也许你需要添加

一些环境设置文件到你的`~/.bashrc`或者手动重新配置他们。

`rosnode` 显示当前运行的ROS节点信息。`rosnode list` 指令列出活跃的节点:

```
$ rosnode list
```

- 你会看到:

  ```
  /rosout
  ```

- **注意**：需要在新的Teminal中写上面命令，不要关闭原来的那个，否则原先的master会节点会被关掉，通常会出现错误：Unable to communicate with master!。解决方法就是：运行roscore,然后开启另一个Teminal。

#### 5. 使用 rosrun

`rosrun` 允许你使用包名直接运行一个包内的节点(而不需要知道这个包的路径)。

用法:

```
$ rosrun [package_name] [node_name]
```

现在我们可以运行turtlesim包中的 turtlesim_node。

然后, 在一个 **新的终端**:

```
$ rosrun turtlesim turtlesim_node
```

你会看到 turtlesim 窗口:

![turtlesim.png](http://wiki.ros.org/cn/ROS/Tutorials/UnderstandingNodes?action=AttachFile&do=get&target=turtlesim.png)

**注意:** 这里的 turtle 可能和你的 turtlesim 窗口不同。别担心，这里有[许多版本的turtle](http://wiki.ros.org/Distributions#Current_Distribution_Releases) ，而你的是一个惊喜!（一个可爱的小彩蛋～）

在一个 **新的终端**:

```
$ rosnode list
```

你会看见类似于:

```
/rosout
/turtlesim
```

ROS的一个强大特性就是你可以通过命令行重新配置名称。

关闭 turtlesim 窗口停止运行节点 (或者回到`rosrun turtlesim`终端并使用`ctrl

-C`)。现在让我们重新运行它，但是这一次使用[Remapping Argument](http://wiki.ros.org/Remapping%20Arguments)改变节点名称:

```
$ rosrun turtlesim turtlesim_node __name:=my_turtle
```

现在，我们退回使用 `rosnode list`:

```
$ rosnode list
```

- 你会看见类似于:

  ```
  /rosout
  /my_turtle
  ```

**注意:** 如果你仍看到 /turtlesim在列表中，这可能意味着你在终端中使用`ctrl-C`停

止节点而不是关闭窗口，或者你没有$ROS_HOSTNAME环境变量，这在

[Network Setup - Single Machine Configuration](http://www.ros.org/wiki/ROS/NetworkSetup#Single_machine_configuration)中有定义。你可以尝试清除rosnode

列表，通过: $ rosnode cleanup

我们可以看到新的`/my_turtle` 节点。使用另外一个 `rosnode` 指令, `ping`, 来

测试:

```
$ rosnode ping my_turtle
```

```
rosnode: node is [/my_turtle]
pinging /my_turtle with a timeout of 3.0s
xmlrpc reply from http://aqy:42235/     time=1.152992ms
xmlrpc reply from http://aqy:42235/     time=1.120090ms
xmlrpc reply from http://aqy:42235/     time=1.700878ms
xmlrpc reply from http://aqy:42235/     time=1.127958ms
```

- roscore = ros+core : master (provides name service for ROS) + rosout

(stdout/stderr) + parameter server (parameter server will be introduced

later)

- rosnode = ros+node : ROS tool to get information about a node.
- rosrun = ros+run : runs a node from a given package.

### 理解ROS话题

**Description:** 本教程介绍ROS话题（topics）以及如何使用[rostopic](http://wiki.ros.org/rostopic) 和 [rxplot](http://wiki.ros.org/rxplot) 命令行工具。

#### 开始

##### **roscore**

首先确保roscore已经运行, 打开一个新的终端：

```
$ roscore
```

如果你没有退出在上一篇教程中运行的roscore，那么你可能会看到下面的错误信息：

```
roscore cannot run as another roscore/master is already running.
Please kill other roscore/master processes before relaunching
```

##### turtlesim

在本教程中我们也会使用到turtlesim，请**在一个新的终端中**运行：

```
$ rosrun turtlesim turtlesim_node
```

##### 通过键盘远程控制turtle

我们也需要通过键盘来控制turtle的运动，请**在一个新的终端中**运行：

```
$ rosrun turtlesim turtle_teleop_key
```

```
[ INFO] 1254264546.878445000: Started node [/teleop_turtle], pid [5528], bound on [aqy], xmlrpc port [43918], tcpros port [55936], logging to [~/ros/ros/log/teleop_turtle_5528.log], using [real] time
Reading from keyboard
---------------------------
Use arrow keys to move the turtle.
```

现在你可以使用键盘上的方向键来控制turtle运动了。如果不能控制，请**选中turtle_teleop_key所在的终端窗口**以确保你的按键输入能够被捕获。

![turtle_key.png](http://wiki.ros.org/cn/ROS/Tutorials/UnderstandingTopics?action=AttachFile&do=get&target=turtle_key.png)

#### ROS Topics

`turtlesim_node`节点和`turtle_teleop_key`节点之间是通过一个ROS**话题**来互相通信的。`turtle_teleop_key`在一个话题上**发布**按键输入消息，而`turtlesim`则**订阅**该话题以接收该消息。下面让我们使用[rqt_graph](http://wiki.ros.org/rqt_graph)来显示当前运行的节点和话题。

**注意**：如果你使用的是`electric`或更早期的版本，那么`rqt`是不可用的，请使用`rxgraph`代替。

##### 使用 rqt_graph

`rqt_graph`能够创建一个显示当前系统运行情况的动态图形。rqt_graph是`rqt`程序包中的一部分。如果你没有安装，请通过以下命令来安装：

```
$ sudo apt-get install ros-<distro>-rqt
$ sudo apt-get install ros-<distro>-rqt-common-plugins
```

请使用你的ROS版本名称（比如fuerte、groovy、hydro等）来替换掉<distro>。

**在一个新终端中**运行:

```
$ rosrun rqt_graph rqt_graph
```

如果你将鼠标放在`/turtle1/command_velocity`上方，相应的ROS节点（蓝色和绿色）和话题（红色）就会高亮显示。正如你所看到的，`turtlesim_node`和`turtle_teleop_key`节点正通过一个名为 `/turtle1/command_velocity`的话题来互相通信。

![rqt_graph_turtle_key2.png](http://wiki.ros.org/cn/ROS/Tutorials/UnderstandingTopics?action=AttachFile&do=get&target=rqt_graph_turtle_key2.png)

##### rostopic介绍

`rostopic`命令工具能让你获取有关ROS**话题**的信息。

你可以使用帮助选项查看`rostopic`的子命令：

```
$ rostopic -h
```

- ```
  rostopic bw     display bandwidth used by topic
  rostopic echo   print messages to screen
  rostopic hz     display publishing rate of topic
  rostopic list   print information about active topics
  rostopic pub    publish data to topic
  rostopic type   print topic type
  ```

接下来我们将使用其中的一些子命令来查看turtlesim。

#### 使用 rostopic echo

`rostopic echo`可以显示在某个话题上发布的数据。

用法：

```
rostopic echo [topic]
```

让我们在**一个新终端中**看一下`turtle_teleop_key`节点在`/turtle1/command_velocity`话题（非hydro版）上发布的数据。

```
$ rostopic echo /turtle1/command_velocity
```

如果你是用ROS Hydro 及其之后的版本（下同），请运行：

```
$ rostopic echo /turtle1/cmd_vel
```

你可能看不到任何东西因为现在还没有数据发布到该话题上。接下来我们通过按下方向键使`turtle_teleop_key`节点发布数据。**记住如果turtle没有动起来的话就需要你重新选中turtle_teleop_key节点运行时所在的终端窗口。**

现在当你按下向上方向键时应该会看到下面的信息：

```
---
linear: 2.0
angular: 0.0
---
linear: 2.0
angular: 0.0
---
```

现在让我们再看一下`rqt_graph`（你可能需要刷新一下ROS graph）。正如你所看到的，`rostopic echo`(红色显示部分）现在也**订阅**了`turtle1/command_velocity`话题。

![rqt_graph_echo.png](http://wiki.ros.org/cn/ROS/Tutorials/UnderstandingTopics?action=AttachFile&do=get&target=rqt_graph_echo.png)

##### 使用 rostopic list

`rostopic list`能够列出所有当前订阅和发布的话题。

让我们查看一下`list`子命令需要的参数，在**一个新终端中**运行：

```
$ rostopic list -h
```

- ```
  Usage: rostopic list [/topic]

  Options:
    -h, --help            show this help message and exit
    -b BAGFILE, --bag=BAGFILE
                          list topics in .bag file
    -v, --verbose         list full details about each topic
    -p                    list only publishers
    -s                    list only subscribers
  ```

在`rostopic list`中使用**verbose**选项：

```
$ rostopic list -v
```

这会显示出有关所发布和订阅的话题及其类型的详细信息。

```
Published topics:
 * /turtle1/color_sensor [turtlesim/Color] 1 publisher
 * /turtle1/command_velocity [turtlesim/Velocity] 1 publisher
 * /rosout [roslib/Log] 2 publishers
 * /rosout_agg [roslib/Log] 1 publisher
 * /turtle1/pose [turtlesim/Pose] 1 publisher

Subscribed topics:
 * /turtle1/command_velocity [turtlesim/Velocity] 1 subscriber
 * /rosout [roslib/Log] 1 subscriber
```

#### ROS Messages

话题之间的通信是通过在节点之间发送ROS**消息**实现的。对于发布器(`turtle_teleop_key`)和订阅器(`turtulesim_node`)之间的通信，发布器和订阅器之间必须发送和接收相同**类型**的消息。这意味着话题的**类型**是由发布在它上面的消息**类型**决定的。使用`rostopic type`命令可以查看发布在某个话题上的消息**类型**。

#### 使用 rostopic type

`rostopic type` 命令用来查看所发布话题的消息类型。

用法：

```
rostopic type [topic]
```

运行(非hydro版)：

```
$ rostopic type /turtle1/cmd_vel
你应该会看到:
geometry_msgs/Twist
```

#### 继续学习 rostopic

现在我们已经了解了什么是ROS的**消息**，接下来我们开始结合消息来使用rostopic。

##### 使用 rostopic pub

`rostopic pub`可以把数据发布到当前某个正在广播的话题上。

用法：

```
$ rostopic pub -1 /turtle1/cmd_vel geometry_msgs/Twist -- '[2.0, 0.0, 0.0]' '[0.0, 0.0, 1.8]'
```

以上命令会发送一条消息给turtlesim，告诉它以2.0大小的线速度和1.8大小的角速度开始移动。

- ![turtle(rostopicpub).png](http://wiki.ros.org/cn/ROS/Tutorials/UnderstandingTopics?action=AttachFile&do=get&target=turtle%28rostopicpub%29.png)

这是一个非常复杂的例子，因此让我们来详细分析一下其中的每一个参数。

- ```
  rostopic pub
  ```

  - 这条命令将会发布消息到某个给定的话题。

- ```
   -1
   ```
  ```

  - （单个破折号）这个参数选项使rostopic发布一条消息后马上退出。

- ```
  /turtle1/cmd_vel
  ```

  - 这是消息所发布到的话题名称。

- ```
  geometry_msgs/Twist
  ```

  - 这是所发布消息的类型。

- ```
  --
  ```

  - （双破折号）这会告诉命令选项解析器接下来的参数部分**都不是**命令选项。这在参数里面包含有破折号`-`（比如负号）时是必须要添加的。

- ```
  '[2.0, 0.0, 0.0]' '[0.0, 0.0, 1.8]'
  ```

  - 正如之前提到的，在一个`turtlesim/Velocity`消息里面包含有两个浮点型元素：`linear`和`angular`。在本例中，`2.0`是`linear`的值，`1.8`是`angular`的值。这些参数其实是按照YAML语法格式编写的，这在[YAML文档](http://wiki.ros.org/ROS/YAMLCommandLine)中有更多的描述。

你可能已经注意到turtle已经停止移动了。这是因为turtle需要一个稳定的频率为1Hz的命令流来保持移动状态。我们可以使用`rostopic pub -r`命令来发布一个稳定的命令流

hydro版：

```
$ rostopic pub /turtle1/cmd_vel geometry_msgs/Twist -r 1 -- '[2.0, 0.0, 0.0]' '[0.0, 0.0, 1.8]'
```

这条命令以1Hz的频率发布速度命令到速度话题上。

- ![turtle(rostopicpub)2.png](http://wiki.ros.org/cn/ROS/Tutorials/UnderstandingTopics?action=AttachFile&do=get&target=turtle%28rostopicpub%292.png)

我们也可以看一下`rqt_graph`中的情形，可以看到rostopic发布器节点（红色）正在与rostopic echo节点（绿色）进行通信：

![rqt_graph_pub.png](http://wiki.ros.org/cn/ROS/Tutorials/UnderstandingTopics?action=AttachFile&do=get&target=rqt_graph_pub.png)

正如你所看到的，turtle正沿着一个圆形轨迹连续运动。我们可以在**一个新终端**中通过`rostopic echo`命令来查看turtlesim所发布的数据。

##### 使用 rostopic hz

`rostopic hz`命令可以用来查看数据发布的频率。

用法：

```
rostopic hz [topic]
```

我们看一下`turtlesim_node`发布`/turtle/pose`时有多快：

```
$ rostopic hz /turtle1/pose
```

现在我们可以知道了turtlesim正以大约60Hz的频率发布数据给turtle。我们也可以结合`rostopic type`和`rosmsg show`命令来获取关于某个话题的更深层次的信息

```
rostopic type /turtle1/cmd_vel | rosmsg show
```

到此我们已经完成了通过`rostopic`来查看话题相关情况的过程，接下来我将使用另一个工具来查看turtlesim发布的数据。

#### 使用 rqt_plot

`rqt_plot`命令可以实时显示一个发布到某个话题上的数据变化图形。这里我们将使用`rqt_plot`命令来绘制正在发布到`/turtle1/pose`话题上的数据变化图形。首先，在一个新终端中运行`rqt_plot`命令：

```
$ rosrun rqt_plot rqt_plot
```

这会弹出一个新窗口，在窗口左上角的一个文本框里面你可以添加需要绘制的话题。在里面输入`/turtle1/pose/x`后之前处于禁用状态的加号按钮将会被使能变亮。按一下该按钮，并对`/turtle1/pose/y`重复相同的过程。现在你会在图形中看到turtle的x-y位置坐标图。

![rqt_plot.png](http://wiki.ros.org/cn/ROS/Tutorials/UnderstandingTopics?action=AttachFile&do=get&target=rqt_plot.png)

按下减号按钮会显示一组菜单让你隐藏图形中指定的话题。现在隐藏掉你刚才添加的话题并添加`/turtle1/pose/theta`，你会看到如下图所示的图形：

![rqt_plot2.png](http://wiki.ros.org/cn/ROS/Tutorials/UnderstandingTopics?action=AttachFile&do=get&target=rqt_plot2.png)

本部分教程到此为止，请使用`Ctrl-C`退出`rostopic`命令，但要保持turtlesim继续运行。

