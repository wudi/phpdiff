phpdiff
=======

---

**THE REPO IS UNMAINTAINED.**

---

[bsdiff](http://www.daemonology.net/bsdiff/ "bsdiff") for php extension 二进制差异包工具php扩展

1. 对新旧两个文件的二进制对比，生成差异文件；
2. 使用旧文件和差异包生成新文件

## Requirements(依赖环境)

bzip2 http://www.bzip.org/downloads.html

Download bzip2 and **use make && make install**

## Installation(安装PHP扩展)

1. git clone https://github.com/EagleWu/phpdiff.git
2. cd phpdiff
3. phpize
4. export LDFLAGS="-lbz2" && ./configure --with-php-config=/php-path/bin/php-config
5. make && make install
6. echo "extension=phpdiff.so" >> /php-path/etc/php.ini

## Usage(使用方法)

##### (bool) bsdiff(oldfile, newfile, diff.patch)

```php
<?php

 //being create the diff.patch file
 bsdiff('oldfile.txt', 'newfile.txt', 'diff.patch');

```

##### (bool) bspatch(oldfile, newfile, diff.patch)

```php
<?php

 //being create newfile with the above diff.patch
 bspatch('oldfile.txt', 'newfile_with_patch.txt', 'diff.patch');

```

## Try Demo(测试文件demo目录下)

```shell
eagle@Macbok-Pro:[~/Source/phpdiff]$tree demo/
demo/
├── diff.php
├── newfile.txt
├── oldfile.txt
└── patch.php

0 directories, 4 files
```

