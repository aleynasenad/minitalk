📡 Minitalk – UNIX Sinyalleri ile İletişim

42 Yazılım Okulu'nda geliştirdiğim Minitalk projesi, UNIX sinyalleri kullanarak client ve server arasında veri iletimi sağlayan basit bir programdır. Bu projede bit işleme mantığı ile yalnızca SIGUSR1 ve SIGUSR2 sinyalleri ile client-server iletişimi gerçekleştirdim.


🛠 Proje Amacı

Minitalk, client ve server arasında basit bir veri iletimi sağlamak için geliştirilmiştir. Server, client'tan aldığı string mesajları alır ve ekrana yazdırır. Bu iletişim, sadece SIGUSR1 ve SIGUSR2 sinyalleri kullanılarak yapılmaktadır. Bu proje ile UNIX sinyalleri ve sinyal yönetimi konularında önemli deneyimler kazandım.


💡 Nasıl Çalışır?

Server: Başlatıldığında PID’sini yazdırır ve client’tan gelen string verisini alarak ekrana yazdırır.

Client: Server’ın PID’sini ve iletilecek string’i parametre olarak alır ve sinyaller kullanarak veriyi server’a iletir.


📥 Server ve Client Kullanımı

Server’ı Başlatma: Terminalde ./server komutuyla server başlatılır ve PID ekrana yazdırılır.

Client’ı Başlatma: Terminalde ./client <server_pid> <string_to_send> komutuyla client çalıştırılır. Burada <server_pid>, server tarafından sağlanan PID’yi ve <string_to_send> ise iletilecek string verisini temsil eder.


🔧 Teknik Detaylar ve Gereksinimler

Sinyaller: İletişim yalnızca SIGUSR1 ve SIGUSR2 sinyalleri kullanılarak yapılır.

Performans: Server, gelen string’leri hızlı bir şekilde yazdırabilmelidir. 100 karakterden uzun mesajlarda performans dikkatlice izlenmelidir.

Arka Arkaya Birden Fazla Client: Server, birden fazla client'tan gelen mesajları alabilmeli ve her birini sırasıyla ekrana yazdırabilmelidir. Server’ın yeniden başlatılması gerekmez.


🎯 Bonus Özellikler

Mesaj Onayı: Server, her mesajı aldıktan sonra client’a bir sinyal göndererek mesajı onaylar.
Unicode Desteği: Server, Unicode karakterlerini doğru şekilde işleyebilir ve yazdırabilir.


⚠️ Önemli Notlar
Bu program, client ve server arasında asenkron bir şekilde iletişim sağlar. Bu nedenle doğru sinyal yönetimi ve zamanlama çok önemlidir. Server’in string’i oldukça hızlı bir şekilde görüntülemesi gerekir. Çok uzun sürdüğünü düşünüyorsanız muhtemelen çok uzundur. 100 karakter görüntülemek için 1 saniye çok fazla!


🎯 Öğrendiklerim

Minitalk projesi, UNIX sinyalleri ile iletişim kurma, asenkron programlama ve sinyal yönetimi hakkında değerli deneyimler kazandırdı. SIGUSR1 ve SIGUSR2 sinyalleriyle veri iletimini sağlarken, PID yönetimi, performans optimizasyonu ve sinyal zamanlamasını daha etkili kullanmayı öğrendim. Ayrıca, sinyalleri bit işleyerek iletme konusunda önemli bir deneyim kazandım. Server’dan geri sinyal gönderirken global değişken kullandım ve bu süreçte volatileve sig_atomic_t anahtar kelimelerinin kullanımını öğrendim. Tüm bunlar, programda sinyalleri doğru bir şekilde yönetebilmek için kritik öneme sahipti. Bu proje, aynı zamanda UNIX sinyallerini nasıl handle edebileceğimi ve verimli bir şekilde nasıl yönetebileceğimi anlamamı sağladı.
