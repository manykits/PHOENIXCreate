#ifndef RANGESENSOR_H
#define RANGESENSOR_H

#include <vector>
#include "sensor.h"
#include "point.h"

namespace GMapping{

class RangeSensor: public Sensor
{
	friend class Configuration;
	friend class CarmenConfiguration;
	friend class CarmenWrapper;
	public:
		
		struct Beam
		{
			OrientedPoint pose;	//pose relative to the center of the sensor     相对于传感器中心位置的姿态
			double span;	    //spam=0 indicates a line-like beam             缺省值为零
			double maxRange;	//maximum range of the sensor                   最大范围
			double s,c;		    //sinus and cosinus of the beam (optimization); 对应的 cos 和 sin 值
		};

		RangeSensor(std::string name);
		
		RangeSensor(std::string name, unsigned int beams, double res, const OrientedPoint& position=OrientedPoint(0,0,0), double span=0, double maxrange=89.0);
		
		inline const std::vector<Beam>& beams() const {return m_beams;}
		
		inline std::vector<Beam>& beams() {return m_beams;}
		
		inline OrientedPoint getPose() const {return m_pose;}
		
		void updateBeamsLookup();
		
		bool newFormat;
	
	protected:
	
		OrientedPoint m_pose; /* 激光器在机器人坐标系中的坐标位置  */
		
		std::vector<Beam> m_beams;
};

};

#endif
