# ft_printf

42 okulunun printf projesinin implementasyonu - C standard library printf fonksiyonunun yeniden yazılması.

## 📋 Proje Hakkında

ft_printf, C standard library'sindeki printf fonksiyonunun sıfırdan implementasyonudur. Bu proje, variadic fonksiyonlar, format specifier'lar ve formatlı çıktı üretimi gibi ileri seviye C programlama kavramlarını öğretir.

## 🎯 Özellikler

### Desteklenen Format Belirteçleri

- `%c` - Karakter yazdırma
- `%s` - String yazdırma  
- `%p` - Pointer adresi (hexadecimal)
- `%d` - Ondalık sayı (decimal)
- `%i` - Integer
- `%u` - Unsigned decimal
- `%x` - Hexadecimal (küçük harf)
- `%X` - Hexadecimal (büyük harf)
- `%%` - Yüzde işareti

### Özellikler

- ✅ Variadic fonksiyon implementasyonu
- ✅ Birden fazla format belirteci desteği
- ✅ Hata yönetimi
- ✅ Original printf ile uyumlu çıktı

## 🛠️ Teknolojiler

- **C Dili** (78.7%)
- **Makefile** (21.3%)
- Variadic functions (stdarg.h)
- Format parsing

## 📦 Kurulum

### Derleme

```bash
make        # Kütüphaneyi derle
make clean  # Object dosyalarını temizle
make fclean # Tüm derleme çıktılarını temizle
make re     # Yeniden derle
```

## 💻 Kullanım

### Projenize Dahil Etme

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Merhaba %s!\n", "Dünya");
    ft_printf("Sayı: %d\n", 42);
    ft_printf("Hex: %x\n", 255);
    ft_printf("Pointer: %p\n", &main);
    
    return (0);
}
```

### Derleme

```bash
gcc main.c libftprintf.a -o program
./program
```

## 📚 Fonksiyon Prototipi

```c
int ft_printf(const char *format, ...);
```

**Dönüş Değeri:** Yazdırılan karakter sayısı

## 🧪 Test Örnekleri

```c
// Temel kullanım
ft_printf("Hello World\n");

// Çoklu format belirteçleri
ft_printf("Name: %s, Age: %d\n", "Alice", 25);

// Hexadecimal çıktı
ft_printf("Address: %p\n", ptr);
ft_printf("Hex: %x, HEX: %X\n", 42, 42);

// Unsigned sayılar
ft_printf("Unsigned: %u\n", 4294967295);
```

## 🎓 Öğrenilen Kavramlar

- **Variadic Functions**: `va_list`, `va_start`, `va_arg`, `va_end`
- **Format Parsing**: String parsing ve format specifier tanıma
- **Type Conversion**: Farklı veri tiplerinin string'e dönüşümü
- **Buffer Management**: Efficient output buffering
- **Edge Cases**: NULL pointer'lar, boş string'ler vb.

## 📝 42 Norm Uyumluluğu

Bu proje 42 okul kodlama standartlarına uygundur:
- Fonksiyon başına maksimum 25 satır
- Satır başına maksimum 80 karakter
- Strict formatting ve isimlendirme kuralları

## 📧 İletişim

Proje Sahibi: TroubledKezoo1

Proje Linki: [https://github.com/TroubledKezoo1/ft_printf](https://github.com/TroubledKezoo1/ft_printf)