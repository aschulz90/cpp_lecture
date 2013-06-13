#include "profiler.hpp"
#include <iostream>

namespace Prof {

	const double CLOCK_TICKTIME = std::chrono::high_resolution_clock::period::num/double(std::chrono::high_resolution_clock::period::den);
	typedef std::chrono::high_resolution_clock clock;

	// ********************************************************************* //
	// ProfileStack
	// ********************************************************************* //

	void ProfileStack::push()
	{
		m_TimeStack.push(clock::period::den);
		// TODO: create a new counter for the current scope/calldepth on the stack
	}

	Ticks ProfileStack::pop( const Ticks& functionTime )
	{
		// TODO: return the time occupied in subfunctions and update the
		// parent function's counter on the stack.
		return functionTime - m_TimeStack.pop;
	}

	ProfileStack ProfileStack::getInstance(){
		return instance;
	}


	
	// ********************************************************************* //
	// ProfileCollector
	// ********************************************************************* //
	ProfileCollector::~ProfileCollector()
	{
		std::chrono::high_resolution_clock::now();
		std::cerr << "Consumed time in    " << m_function << "()   [" << m_file << "] :\n    ";
		std::cerr << (m_collectetedTime*CLOCK_TICKTIME*1000.0) << " ms    [";
		std::cerr << (m_collectetedTimeExclusive*CLOCK_TICKTIME*1000.0) << " ms]\n";
	}



	// ********************************************************************* //
	// ScopeProfiler
	// ********************************************************************* //
	ScopeProfiler::ScopeProfiler( ProfileCollector& collector ) :
			m_collector( collector )
	{
		m_startPoint = std::chrono::high_resolution_clock::now();
		// TODO: Use ProfilerStack
		pStack = pStack.getInstance();
		pStack.push();
	}

	ScopeProfiler::~ScopeProfiler()
	{
		Ticks timeSpan = (std::chrono::high_resolution_clock::now()-m_startPoint).count();
		// TODO: Use ProfilerStack
		pStack.pop(timeSpan);
		Ticks subTime = 0;
		m_collector.addTime( timeSpan, timeSpan-subTime );
	}

};