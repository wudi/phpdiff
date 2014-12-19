phpdiff
=======

[bsdiff](http://www.daemonology.net/bsdiff/ "bsdiff") for php extension

##Installation

1. git clone https://github.com/EagleWu/phpdiff.git
2. cd phpdiff
3. phpize
4. ./configure --with-php-config=/php-path/bin/php-config
5. make && make install
6. echo "extension=phpdiff.so" >> /php-path/etc/php.ini

##Usage

#####(bool) bsdiff()

```php
<?php

 bsdiff('oldfile.txt', 'newfile.txt', 'diff.patch');

```

#####(bool) bspatch()

```php
<?php

bspatch('oldfile.txt', 'newfile_with_patch.txt', 'diff.patch');

```

##Demo

eagle@Macbok-Pro:[~/Source/phpdiff]$tree demo/
demo/
├── diff.php
├── newfile.txt
├── oldfile.txt
└── patch.php

0 directories, 4 files

