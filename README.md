# Solar Tracker Dual Axis Berbasis ESP32

Sistem pelacak matahari dua sumbu yang mengoptimalkan penyerapan energi panel surya 12W agar lebih efisien dan responsif terhadap pergerakan cahaya.
1.	Panel Surya
Panel surya adalah alat yang berfungsi mengubah energi cahaya matahari menjadi energi listrik melalui efek fotovoltaik. Besarnya energi yang dihasilkan sangat dipengaruhi oleh intensitas cahaya dan posisi panel terhadap matahari.
1.	Sensor LDR
LDR (Light Dependent Resistor) adalah sensor yang nilai resistansinya berubah sesuai dengan intensitas cahaya. Semakin terang cahaya yang diterima, maka nilai resistansi akan semakin kecil. Pada project ini digunakan 4 buah LDR untuk mendeteksi arah datangnya cahaya.
2.	ESP32
ESP32 adalah mikrokontroler yang berfungsi sebagai pusat pengolahan data. ESP32 membaca data dari sensor LDR, mengolahnya, lalu mengirimkan perintah ke motor servo untuk bergerak ke arah cahaya yang paling terang.
3.	Motor Servo MG995
Motor servo MG995 adalah motor servo dengan sudut gerak hingga 180 derajat. Motor ini digunakan sebagai penggerak panel surya pada sumbu horizontal dan vertikal.
6.	Baterai Lithium-ion
Baterai lithium-ion digunakan untuk menyimpan energi listrik dari panel surya. Baterai ini memiliki kapasitas besar dan dapat digunakan kembali.
7.	Solar Charge Controller
Solar charge controller berfungsi untuk mengatur proses pengisian baterai agar tidak terjadi overcharge atau kerusakan baterai.

Sistem solar tracker terdiri dari panel surya, 4 sensor LDR, ESP32, motor servo MG995, baterai Li-ion, dan solar charge controller. Sensor LDR dipasang di sekitar panel surya untuk mendeteksi intensitas cahaya dari berbagai arah. ESP32 bertugas mengolah data dari sensor dan mengendalikan motor servo.
Baterai Li-ion dihubungkan ke panel surya melalui solar charge controller dan tidak langsung terhubung ke ESP32.
