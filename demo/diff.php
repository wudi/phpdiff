<?php
if (!extension_loaded("phpdiff")) 
	die("phpdiff extension not install");

var_dump(bsdiff('oldfile.txt', 'newfile.txt', 'diff.patch'));