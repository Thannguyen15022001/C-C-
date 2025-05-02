CXX = g++
CXXFLAGS =-I . -Wl,-rpath=.
OBJECT = Dynamic_lib.o
LIB = libDynamic.so
SOURCE = main.cpp
.PHONY: all clean

all: main

main: $(SOURCE) $(LIB)
	$(CXX) $(CXXFLAGS) -o $@ $< -L . -lDynamic  

$(LIB): $(OBJECT)
	$(CXX) -shared $^ -o $@

%.o: %.cpp
	$(CXX) -fPIC -o $@ -c $<

clean:
	rm -rf *.o *.so


# Flag -L . chỉ báo cho compiler thư biện .so ở đâu để cần link cho file main
# Có 3 cách để set đường dẫn cho thư viện .so khi excute chương trình
# 1. Set đường dẫn thư viện có biến môi trường LD_LIBRARY_PATH
# 2. Thêm flag -Wl,-rpath=. khi build file thực thi, để nhúng thông tin thư mục .so vào file thực thi:
# 3. Thêm thư viện .so vào /usr/lib, /usr/local/lib + chạy ldconfig

# Biến môi trường LD_LIBRARY_PATH trong Linux có chức năng chỉ định thư mục mà hệ điều hành sẽ tìm các thư viện động (.so) tại thời điểm chạy chương trình.
# LD_LIBRARY_PATH chỉ ảnh hưởng tại thời điểm chạy.
# Không ảnh hưởng đến lúc biên dịch hay link.
# Chỉ có tác dụng với thư viện động (.so), không áp dụng với .a (static lib).

#Nên build ra file .d để trace sự thay đổi của file header