echo ""
echo "Starting Cleanup"
echo ""
make clean
echo ""
echo "Building Project"
echo ""
make 
echo ""
echo "Build Complete"
echo ""
echo "Running Project"
echo ""
make file=$1 run
echo ""