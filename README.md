# Akıllı Otopark Sistemi
Bu proje, bir Arduino Uno, breadboard, servo motor ve IR proximity sensör kullanarak geliştirilmiş bir akıllı otopark sistemidir. Sistem, otoparka giriş ve çıkış yapan araçları algılar, otoparktaki boş yer sayısını günceller ve kapasite dolu olduğunda yeni araç girişini engeller.





https://github.com/cemilcan99/SmartPark/assets/65957701/45255aee-5c4a-442c-b5fa-ac7426d23672





      
## Gereksinimler
Bu projeyi çalıştırmak için aşağıdaki donanım ve yazılımlara ihtiyacınız var:

- Arduino Uno
* Breadboard
+ Servo Motor
- IR Proximity Sensör (2 adet)
* Jumper Kabloları
+ LCD 16x2 I2C Ekran
- Arduino IDE

## Kurulum
#### Devreyi Kurma:

Servo motoru ve IR proximity sensörlerini breadboard üzerinde Arduino Uno'ya bağlayın.
Servo motorun kontrol pinini Arduino'nun dijital pinlerinden birine (örneğin, pin 7) bağlayın.
IR sensörlerinin birini giriş algılama için diğerini çıkış algılama için kullanacağız. Bu sensörlerin çıkış pinlerini Arduino'nun dijital pinlerine (örneğin, pin 2 ve pin 4) bağlayın.
LCD 16x2 I2C ekranı uygun şekilde bağlayın.

#### Gerekli Kütüphaneleri Yükleme:

Arduino IDE'yi açın ve "Sketch" menüsünden "Include Library" > "Add .ZIP Library..." seçeneğine tıklayın.
*LCD16x2_I2C* kütüphanesini ekleyin. Bu kütüphane dosyasını proje içerisinde bulabilirsiniz.

#### Arduino Kodunu Yükleme:

Bu projeyi çalıştırmak için gerekli olan kodu _**SmartPark.ino**_ dosyasından Arduino'ya yükleyin.
Arduino IDE'yi açın,  _**SmartPark.ino**_ dosyasını yükleyin ve kodu Arduino Uno'ya yüklemek için "Yükle" butonuna tıklayın.

#### Kullanım
Sistemi çalıştırmak için Arduino'yu bir güç kaynağına bağlayın.
IR sensörleri, bir araç giriş veya çıkış yaptığında bunu algılar ve Arduino'ya sinyal gönderir.
Arduino, servo motoru kullanarak otopark kapısını açar ve kapatır.
Araç girişi ve çıkışı yapıldıkça otopark kapasitesi güncellenir.
Otopark dolduğunda yeni araçların giriş yapması engellenir.
