/* vim: set sw=4 sts=4 et foldmethod=syntax : */

#ifndef GUARD_SERIALIZERS_HH
#define GUARD_SERIALIZERS_HH 1

#include <boost/serialization/split_free.hpp>

#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>

BOOST_SERIALIZATION_SPLIT_FREE(cv::Mat);

namespace boost
{
    namespace serialization
    {
        // OpenCV Point<>.
        template <typename Archive_, typename PointType_>
        void serialize(Archive_ & archive, cv::Point_<PointType_> & point, const unsigned int version)
        {
            archive & point.x;
            archive & point.y;
        }

        // OpenCV KeyPoint.
        template <typename Archive_>
        void serialize(Archive_ & archive, cv::KeyPoint & key_point, const unsigned int version)
        {
            archive & key_point.pt;
            archive & key_point.size;
            archive & key_point.angle;
            archive & key_point.response;
            archive & key_point.octave;
            archive & key_point.class_id;
        }

        // OpenCV Mat.
        template <typename Archive_>
        void save(Archive_ & archive, const cv::Mat & m, const unsigned int version)
        {
            size_t element_type(m.type());
            size_t element_size(m.elemSize());

            archive & m.cols;
            archive & m.rows;
            archive & element_size;
            archive & element_type;

            size_t size(m.cols * m.rows * element_size);

            for (size_t i(0); i < size; ++i)
                archive & m.data[i];
        }

        template <typename Archive_>
        void load(Archive_ & archive, cv::Mat & m, const unsigned int version)
        {
            int cols;
            int rows;

            size_t element_type;
            size_t element_size;

            archive & cols;
            archive & rows;
            archive & element_size;
            archive & element_type;

            m.create(rows, cols, element_type);

            size_t size(m.cols * m.rows * element_size);

            for (size_t i(0); i < size; ++i)
                archive & m.data[i];
        }
    }
}

#endif
