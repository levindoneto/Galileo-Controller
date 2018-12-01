echo ">>> Cleaning all .o, .d and exutables... <<<";
cd lib/;
make clean distclean;
cd ../src;
make clean distclean;
echo ">>> All cleaned up! <<<";
