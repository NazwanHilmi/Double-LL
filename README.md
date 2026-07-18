
# Double Linked List

Project untuk membuat program Double Linked List sebagai Tugas Besarr UAS


## Install Git SCM

- Donwload terlebih dahulu Git SCM di link berikut [Git SCM](https://github.com/git-for-windows/git/releases/download/v2.55.0.windows.3/Git-2.55.0.3-64-bit.exe)
- Kemudian Install dan ikuti langkah-langkah nya




- Dibagian ini klik next-next saja :
![App Screenshot](https://imglink.cc/cdn/_dnDRUQu_C.png)

- Dibagian "Adjusting your PATH Environment" pilih yang kedua atau "Git from the command line and also from 3rd-party software". Setelah itu klik next kembali sampai ke bagian install.
![App Screenshot](https://imglink.cc/cdn/EiSQWF4s8C.png)
- Klik Finish
![App Screenshot](https://imglink.cc/cdn/LCeXKNEOrD.png)
## Konfigurasi GIT

- Buka GIT Bash
![App Screenshot](https://imglink.cc/cdn/23sD9DbFTh.png)

- Tampilannya seperti ini 
![App Screenshot](https://imglink.cc/cdn/WLL8oS8qF0.png)

Periksa apakah git sudah terpasang :
```bash
  git --version
```
![App Screenshot](https://imglink.cc/cdn/Lut3sk6Lt3.png)

Lakukan konfigurasi pada git :
```bash
  git config --global user.name "Nama Anda"
  git config --global user.email "emailgithub@anda.com"
```
![App Screenshot](https://imglink.cc/cdn/A0lvk8jfgv.png)

- Ganti "Nama Anda" dengan namamu, dan "emailgithub@anda.com" dengan akun yang terhubung dengan Github.

> **📝 Note:**
> Jangan hilangkan ("")

> **📝 Note:**
> Untuk melakukan paste di git bash gunakan Shift + Insert


    
## Github Forking

- Klik Fork pada bagian atas repository github
![App Screenshot](https://imglink.cc/cdn/3KmVkjJQim.png)

- Hapus Centang pada bagian ini lalu Create Fork :
![App Screenshot](https://imglink.cc/cdn/e9andD7NTx.png)

- Buka Git Bash

```bash
cd /c
```
- Clone Fork ke lokal
```bash
git clone https://github.com/username-github/Double-LL.git
cd Double-LL
```
> **📝 Note:**
> Ganti username-github dengan Username Github kamu

Contoh Username : 
![App Screenshot](https://imglink.cc/cdn/pKvhZ1L0a6.png)


- Tambahkan remote ke repo asli
```bash
git remote add upstream https://github.com/NazwanHilmi/Double-LL.git
git remote -v
```

- Buat Branch
```bash
git checkout -b function
```
## Buat Function

- Buka file main.c di Local Disk C -> Double LL -> main.c
- Buka file dengan Dev C, VsCode atau software coding lainnya
- Silahkan buat function nya
- Setelah selesai coding function yang diberikan, buka Git Bash dan jalankan perintah dibawah

```bash
cd C:\Double-LL
```

```bash
git add .
git commit -m "Deskripsi singkat function"
```

```bash
git push origin function
```