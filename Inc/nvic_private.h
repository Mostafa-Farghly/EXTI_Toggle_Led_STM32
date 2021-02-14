/*
 * nvic_private.h
 *
 *  Created on: Jan 18, 2021
 *      Author: 15014
 */

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_


#define GET_IRQ_REG_NUM(X)				((X) / (32))
#define GET_IRQ_BIT_NUM(X)				((X) % (32))
#define GET_IRQ_PRIORITY(X, Y)			(((X) << (6)) | (((Y) & (0x3)) << (4)))


#endif /* NVIC_PRIVATE_H_ */
