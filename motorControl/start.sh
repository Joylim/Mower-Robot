echo "rm -rf build/"
rm -rf build/
echo "mkdir build"
mkdir build
echo "cd build/"
cd build/
echo "cmake --prefix=/usr/local"
cmake -DCMAKE-INSTALL-PREFIX=/usr/local ..
echo "make"
make
echo "make install"
make install
echo "build motorcontrol.a motorcontrol.so successful! and the files is in /usr/local/lib "
