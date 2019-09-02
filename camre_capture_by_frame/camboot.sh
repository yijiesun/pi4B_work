cd /home/pi/work/camre_capture_by_frame
./dirname.sh
cd /home/pi/work/camre_capture_by_frame/build
./cam_cap /home/pi/work/westdata/ 1 1920 1080 4000 2000 bmp |tee log.txt
#                  1           2   3    4    5    6   7
:<<!
* argv[1] 抓取的图片保存的地址
* argv[2] 间隔多少秒抓一帧
* argv[3] 分辨率width
* argv[4] 分辨率height
* argv[5] 低于多少内存的时候开始删除最早的数据（用线程）GB
* argv[6] 低于警戒线内存的时候开始疯狂删除最早的数据GB
* argv[7] 保存的图片格式jpg/bmp/png
!