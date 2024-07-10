# get_next_line

get_next_line fonksiyonu, bir dosya tanıtıcısından veya standart girdiden (stdin) bir satırı okumak için kullanılır. Her çağrıldığında, dosyadan bir sonraki satırı döndürür. Bu işlev, dosya veya veri akışı boyunca ilerlemeyi ve satır satır okumayı kolaylaştırır.

### fonksiyon prototipi
'' int get_next_line(int fd, char **line); ''

#### parametreler
int fd: Okuma yapılacak dosya tanıtıcısı. Bu, dosya veya standart girdiyi temsil eder.

char **line: Okunan satırın depolanacağı bellek adresine işaret eden gösterici. line değişkeni, fonksiyon tarafından ayrılan ve okunan satırı içeren belleği gösterecektir.
