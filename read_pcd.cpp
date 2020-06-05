#include <iostream> 
#include <pcl/io/pcd_io.h> 
#include <pcl/point_types.h> 
#include <pcl/point_cloud.h> 
#include <pcl/visualization/cloud_viewer.h> 
int
main(int argc, char *argv[])
{
	pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZRGB>); 

	if (pcl::io::loadPCDFile<pcl::PointXYZRGB>(argv[1], *cloud) == -1)
	{ 
		std::cout << "Cloud reading failed." << std::endl; return (-1); 
	} 
	std::cout << cloud->width << cloud->height << std::endl; 
	for (size_t i = 0; i < cloud->points.size(); ++i)
	{
		std::cout << cloud->points[i].x << cloud->points[i].y << cloud->points[i].z <<std::endl; 
	}
	pcl::visualization::CloudViewer viewer("Simple Cloud Viewer"); 
	viewer.showCloud(cloud); 
	while (!viewer.wasStopped()) { } 
	system("pause");
	return (0); 
}

