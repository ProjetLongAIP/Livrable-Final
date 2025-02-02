// This file is part of the EXTERNAL RENDERER PLUGIN for V-REP
// 
// Copyright 2006-2015 Coppelia Robotics GmbH. All rights reserved. 
// marc@coppeliarobotics.com
// www.coppeliarobotics.com
// 
// The EXTERNAL RENDERER PLUGIN is licensed under the terms of GNU GPL:
// 
// -------------------------------------------------------------------
// The EXTERNAL RENDERER PLUGIN is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// THE EXTERNAL RENDERER PLUGIN IS DISTRIBUTED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
// WARRANTY. THE USER WILL USE IT AT HIS/HER OWN RISK. THE ORIGINAL
// AUTHORS AND COPPELIA ROBOTICS GMBH WILL NOT BE LIABLE FOR DATA LOSS,
// DAMAGES, LOSS OF PROFITS OR ANY OTHER KIND OF LOSS WHILE USING OR
// MISUSING THIS SOFTWARE.
//  
// See the GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with the EXTERNAL RENDERER PLUGIN.  If not, see <http://www.gnu.org/licenses/>.
// -------------------------------------------------------------------
//
// This file was automatically created for V-REP release V3.2.3 rev4 on December 21st 2015

#include "openglWidget.h"
#include "MyMath.h"
#include <QResizeEvent>

COpenglWidget::COpenglWidget(int associatedObjectHandle,QWidget *parent) : QGLWidget(QGLFormat(true ? (QGL::DoubleBuffer) : (QGL::StereoBuffers)),parent), COpenglBase(associatedObjectHandle)
{
}

COpenglWidget::~COpenglWidget()
{
}

void COpenglWidget::initGL()
{
	setAutoBufferSwap(false);
	COpenglBase::initGL();
}

void COpenglWidget::makeContextCurrent()
{
	QGLWidget::makeCurrent();
}

void COpenglWidget::doneCurrentContext()
{
	QGLWidget::doneCurrent();
}

void COpenglWidget::paintEvent(QPaintEvent* event)
{
//	QGLWidget::paintEvent(event);
}

void COpenglWidget::resizeEvent(QResizeEvent* rEvent)
{
	_resX=rEvent->size().width();
	_resY=rEvent->size().height();
}

void COpenglWidget::paintGL()
{
}

void COpenglWidget::showAtGivenSizeAndPos(int resX,int resY,int posX,int posY)
{
	if ( (resX<=0)||(resY<=0) )
		showMaximized();
	else
	{
		showNormal();
		setGeometry(posX,posY,resX,resY);
	}
}

void COpenglWidget::getWindowResolution(int& resX,int& resY)
{
	resX=_resX;
	resY=_resY;
}

