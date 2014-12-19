<?php
if (!extension_loaded("phpdiff")) 
	die("phpdiff extension not install");

var_dump(bspatch('oldfile.txt', 'newfile_with_patch.txt', 'diff.patch'));