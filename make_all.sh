echo ">>> Making lib and controller";
echo "(It fails if you have not executed the iss_setup script)... <<<";
cd lib/;
make;
cd ../src;
make;
echo ">>> All built, you can transfer to the GalileoGen2! <<<";
