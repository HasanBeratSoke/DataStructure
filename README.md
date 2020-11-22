# DataStructure
homeWork

  #Parantez Parantez Eşleştirme Kontrolü (Matching Bracket Control)#

Kullanılan parantezlerin geçerli olması için 2 kural geçerlidir;
  1.	Açılan parantezlerin sayısı ile kapatılan parantezlerin sayısı eşit olmalı.
  2.	Kapatılan her parantezden önce, bir parantez açılmalıdır.

Bu kontrolü sağlamak için stackler kullanılabilir. Genel algoritması şöyledir:
  •	Her acılan parantez ile karşılaşıldığı zaman o değer Push() edilir.
  •	Her kapatılan parantez ile karşılaşıldığı zaman, Peek() fonksiyonu çalıştırılır ve tepe değeri ile eşleşiyor mu kontrol edilir.
    o	Eğer değerler birbirini karşılıyorsa, değer Pop() edilerek stack’in tepe elemanı çıkartılır.
  •	Son olarak, stack’in dolu mu boş mu kontrolü yapılmalı.
    o	Boş ise: ifade doğrudur.
  o	Boş değil ise: ifade geçersizdir.
