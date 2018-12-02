echo ">>> Cleaning all .o, .d and exutables... <<<";
cd lib/;
make clean distclean;
cd ../src;
make clean distclean;
cd ../;
echo "_______________________";
echo ">>> All cleaned up! <<<";
echo "_______________________";
