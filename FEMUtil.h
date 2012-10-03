/*
 * FEMUtil.h
 *
 *  Created on: Oct 3, 2012
 *      Author: jmonk
 */

#ifndef FEMUTIL_H_
#define FEMUTIL_H_

/**
 * This is a utility class that will be passed to the MessLessHandler being
 * used. It will contain a variety of functions to facilitate the FEM pieces of
 * MFEM.
 *
 */
class FEMUtil {
public:
	FEMUtil();
	virtual ~FEMUtil();
};

#endif /* FEMUTIL_H_ */
