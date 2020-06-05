#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>
#include <string>
#include <iostream>

using pcl::visualization::PointCloudColorHandlerGenericField;
using pcl::visualization::PointCloudColorHandlerCustom;

int 
main(int argc, char *argv[])
{
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_1(new pcl::PointCloud<pcl::PointXYZ>);
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_2(new pcl::PointCloud<pcl::PointXYZ>);

	std::string file_name_1 = "../dataset5pcd/0atte_map_xyzkey0.pcd";
	std::string file_name_2 = "../dataset5pcd/0atte_map_xyzori0.pcd";
	if (pcl::io::loadPCDFile<pcl::PointXYZ>(file_name_1, *cloud_1) == -1) {
		std::cout << "Cloud reading failed." << std::endl; return (-1);
	}
	if (pcl::io::loadPCDFile<pcl::PointXYZ>(file_name_2, *cloud_2) == -1) {
		std::cout << "Cloud reading failed." << std::endl; return (-1);
	}
	pcl::visualization::PCLVisualizer *p;
	int vp_1, vp_2;
	p = new pcl::visualization::PCLVisualizer(argc, argv, "example");
	p->setBackgroundColor(0, 0, 0);
	p->createViewPort(0.0, 0, 0.5, 1.0, vp_1);
	p->createViewPort(0.5, 0, 1.0, 1.0, vp_2);
	p->removePointCloud("source");
	p->removePointCloud("target");
	PointCloudColorHandlerCustom<pcl::PointXYZ>		cloud_tgt_h(cloud_1, 0, 255, 0);
	PointCloudColorHandlerCustom<pcl::PointXYZ>  cloud_src_h(cloud_2, 255, 0, 0);
	p->addPointCloud(cloud_1, cloud_tgt_h, "target", vp_1);
	p->addPointCloud(cloud_2, cloud_src_h, "source", vp_2);
	p->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "target");
	p->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "source");
	p->spin();
	p->removePointCloud("source");
	p->removePointCloud("target");
	return (0);
}
