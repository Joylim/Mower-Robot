echo "rm -rf build/ bin/"
rm -rf build/
rm -rf bin/
echo "mkdir build"
mkdir build
echo "mkdir bin/"
mkdir bin
echo "cd build"
cd build
echo "cmake"
cmake ..
echo "make"
make
