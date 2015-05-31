/*
 * EdgeDetect.h
 *
 *  Created on: 2015年5月26日
 *      Author: hongbohuang
 */

#ifndef SRC_EDGEDETECT_EDGEDETECT_H_
#define SRC_EDGEDETECT_EDGEDETECT_H_
#include <string>
#include <opencv2/opencv.hpp>
#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace std;
class EdgeDetect {
private:
		/*
		 * 图像分块后块的行数
		 */
		int N;

		/*
		 * 图像分块后块的列数
		 */
		int M;

		/*
		 * 分块的边长
		 */
		int GRID;

		/*
		 * 图像像素宽度
		 */
		int WIDTH;

		/*
		 * 图像像素高度
		 */
		int HEIGHT;

		/*
		 * bfs队列, 二元组表示块坐标
		 */
		pair<int, int>* q;
		/*
		 * bfs相邻区域的坐标增量
		 */
		int dx[4];
		int dy[4];
		/*
		 * 二維數組，每个块中白点的个数
		 */
		int** f;
		/*
		 * bfs搜索结果,也是识别结果
		 */
		bool** v;
		/*
		 * 灰度矩阵和canny检测二值化后的图像
		 */
		cv::Mat g, mat;
		CvMat *cannyMat;
		/*
		 * 详见构造函数中的rate1 和rate2
		 */
		double r1, r2;
		/*
		 * bfs过程判断是否出界
		 */
		bool inside(int x, int y);
		/*
		 * 进行bfs
		 */
		void search(int &mm);
public:

		/* destroy 模板函数
		 *  功能: 将二维数组的内存释放
		 *  参数说明:
		 *  Type: 指定二维数组a的类型
		 *  a: a的类型是Type**
		 *      表示一个二维数组
		 *      a[i]的类型是Type*, 表示一个一维数组
		 *  N: 二维数组a的行数
		 *  用法:
		 *  edgeDetector.destroy<int>(a, N);
		 *  这里,edgeDetector是EdgeDetector的一个对象
		 */
		template<class Type>
		static void destroy(Type** a, int N);

		/* clear 模板函数
		 *  功能:将二维数组清零
		 *  参数说明:
		 *  Type:指定二维数组类型
		 *  a: 二维数组
		 *  N:二维数组a的行数
		 *  M:二维数组a的列数
		 *  用法:
		 *  edgeDetector.clear(a, N, M);
		 */
		template<class Type>
		static void clear(
				Type** a,
				int N,
				int M
		);

		/*alloc2d 模板函数
		 * 功能:获取一个N行M列的二维数组
		 * 参数说明
		 * Type:指定二维数组类型
		 * N:二维数组行数
		 * M:二维数组列数
		 * 返回值:一个 指向Type指针的指针  表示一个二维数组
		 * 设返回值为f
		 *      则f[i]的类型是Type*, 表示一个一维数组
		 *  用法:
		 *  int** a = edgeDetector.alloc2d<int>(N, M);
		 *  for (int i = 0; i < N; ++ i) {
		 *  		for (int j = 0; j < M; ++j) {
		 *  				a[i][j] = i + j;
		 *  		}
		 *  }
		 */
		template <class Type>
		static Type** alloc2d(int N, int M);

		/* EdgeDetect类构造函数
		 * 参数说明:
		 * width: 图像的像素宽度
		 * height: 图像的像素高度
		 * grid: 分块的边长
		 * 块的个数为 (width / grid) * (height / grid)
		 * rate1: 0~1 之间的一个值
		 *             设所有图像块中白点个数最多的为max
		 *             bfs开始前,只有当图像底部的块白点个数达到max * rate1时
		 *             该块才会被放进队列
		 * rate2: 0~1 之间的一个值
		 *             在bfs时, 对于非图像最下方一行的块
		 *             只有当白点的个数达到max * rate2时
		 *             才会被放入队列
		 */
		EdgeDetect(
				int width,
				int height,
				int grid,
				double rate1,// = 0.5,
				double rate2// = 0.5
		);

		/* EdgeDetect类 成员函数detect
		 * 功能: 识别图像中的草坪区域
		 * 			判定图像中每一个块是否属于草坪区域
		 * 参数说明:
		 * img:输入的灰度图像
		 * result: 函数输出的bool数组
		 *               result[i][j] = true 时, 表示 算法认为第i行第j列的块为草坪
		 *               否则,为非草坪
		 */
		void detect(
				cv::Mat  img,
				bool**& result
		);

		/* paint函数
		 * 功能:根据识别结果,将输入图像中草坪区域的块涂成白色
		 * 参数说明:
		 * img: 输入的原图像,同时也是输出的图像
		 * result:二维bool数组, 表示识别结果,同detect
		 */
		int paint(
				cv::Mat img,
				bool** &result,
				int &countOfWhite
		);

		/*
		 * 析构函数,释放空间
		 */
		~EdgeDetect();
};

#endif /* SRC_EDGEDETECT_EDGEDETECT_H_ */
