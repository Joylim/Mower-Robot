/*
 * EdgeDetect.cpp
 *
 *  Created on: 2015年5月26日
 *      Author: hongbohuang
 */

#include "EdgeDetect.h"

bool EdgeDetect::inside(int x, int y) {
        if (x < 0) return false;
        if (y < 0) return false;
        if (x >= N) return false;
        if (y >= M) return false;
        return true;
}
void EdgeDetect:: search() {
    	int n = mat.size().height;
    	int m = mat.size().width;
    	clear<int>(f, N, M);
    	clear<bool>(v, N, M);
    	for (int i = 0; i < n; ++ i) {
            	for (int j = 0; j < m; ++ j) {
                    	if (mat.ptr<uchar>(i)[j] > 0) {
                            	f[i / GRID][j / GRID] ++;
                    	}
            	}
    	}
    	int mm = 0;
    	for (int i = 0; i < N; ++ i) {
    			for (int j = 0; j < M; ++ j) {
    					if (mm < f[i][j]) mm = f[i][j];
    			}
    	}
    	int s = 0;
    	int t = 0;
    	for (int j = 0; j < M; ++ j) {
            	if (f[N - 1][j]>=mm*r1) {
            			q[t].first = N - 1;
            			q[t].second = j;
            			v[N - 1][j] = true;
            			t ++;
            	}
    	}
    	while (s < t) {
            	int x = q[s].first;
            	int y = q[s].second;
            	for (int i = 0; i < 4; ++ i) {
                    	int nx = x + dx[i];
                    	int ny = y + dy[i];
                    	if (!inside(nx,ny)) continue;
                    	if (v[nx][ny]) continue;
                    	if (f[nx][ny] < mm * r2) continue;
                    	v[nx][ny] = true;
                    	q[t].first = nx;
                    	q[t].second = ny;
                    	t ++;
            	}
            	s ++;
    	}
}

template <class Type> void EdgeDetect::destroy(Type** a, int N) {
		for (int i = 0; i < N; ++ i) {
				delete[] a[i];
		}
		delete[] a;
}

template <class Type> void EdgeDetect::clear(Type** a, int N, int M) {
		for (int i = 0; i < N; ++ i) {
				for (int j = 0; j < M; ++ j) {
						a[i][j] = 0;
				}
		}
}

template <class Type> Type** EdgeDetect::alloc2d(int N, int M) {
		Type** f = new Type*[N];
		for (int i = 0; i < N; ++ i) {
				f[i] = new Type[M];
		}
		return f;
}

EdgeDetect::EdgeDetect(
		int width,
		int height,
		int grid,
		double rate1,
		double rate2
) {
		WIDTH = width;
		HEIGHT = height;
		GRID = grid;
		N = HEIGHT / GRID;
		M = WIDTH / GRID;
		q = new pair<int, int>[N * M];
		f = alloc2d<int>(N, M);
		v = alloc2d<bool>(N, M);
		r1 = rate1;
		r2 = rate2;
		for (int i = 0; i < 4; ++ i) {
				dx[i] = 0;
				dy[i] = 0;
		}
		dx[0] = -1;
		dx[1] = 1;
		dy[2] = -1;
		dy[3] = 1;
}

void EdgeDetect::detect(cv::Mat gray, bool**& result) {
        cv::Canny(gray, mat, 40, 120);
        cv::threshold(mat, mat, 40, 255, cv::THRESH_BINARY);
        search();
		if (result == NULL) {
				result = alloc2d<bool>(N, M);
		}
        for (int i = 0; i < N; ++ i) {
        		for  (int j = 0; j < M; ++ j) {
        				result[i][j] = v[i][j];
        		}
        }
}

void EdgeDetect::paint(cv::Mat& frame, bool** result) {
    	int n = frame.size().height;
    	int m = frame.size().width;
    	for (int i = 0; i < n; ++ i) {
    			for (int j = 0; j < m; ++ j) {
    					int x = i / GRID;
    					int y = j / GRID;
    					if (v[x][y]) {
    							frame.ptr<uchar>(i)[j * 3] = 255;
    							frame.ptr<uchar>(i)[j * 3 + 1] = 255;
    							frame.ptr<uchar>(i)[j * 3 + 2] = 255;
    					}
    			}
    	}
}

EdgeDetect::~EdgeDetect() {
		destroy<int>(f, N);
		destroy<bool>(v, N);
}
