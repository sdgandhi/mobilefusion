#include "CloudNormalProvider.h"

#include <pcl/search/kdtree.h>
#include <pcl/features/normal_3d.h>

namespace MobileFusion {
    pcl::PointCloud<pcl::Normal>::Ptr CloudNormalProvider::computeNormal(
        const pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud, int k_search) {
        pcl::search::KdTree<pcl::PointXYZRGB>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZRGB>);

        pcl::NormalEstimation<pcl::PointXYZRGB, pcl::Normal> normal_estimation;
        pcl::PointCloud<pcl::Normal>::Ptr normals(new pcl::PointCloud<pcl::Normal>);
        normal_estimation.setInputCloud(cloud);
        normal_estimation.setSearchMethod(tree);
        normal_estimation.setKSearch(k_search);
        normal_estimation.compute(*normals);

        return normals;
    }

}