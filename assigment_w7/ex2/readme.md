## Dưới đây là các lệnh cần thực hiện trên Terminal để tạo thư viện và chạy chương trình:

## A. Thư viện tĩnh (Static Library) 


Tao file doi tuong (.o): 
gcc -c hashtable.c -o hashtable.o


Tao thu vien tinh libhash.a: 
ar rcs libhash.a hashtable.o


Lien ket voi main.c de tao file thuc thi: 
gcc main.c -L. -lhash -o main_static


Chay chuong trinh: 
./main_static

## B. Thư viện động (Dynamic Library - Linux) 


Bien dich voi flag fPIC: 
gcc -fPIC -c hashtable.c -o hashtable.o


Tao file thu vien dong .so: 
gcc -shared -o libhash.so hashtable.o


Lien ket va chay chuong trinh: 
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.
gcc main.c -L. -lhash -o main_dynamic
./main_dynamic