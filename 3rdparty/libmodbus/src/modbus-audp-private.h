/*
 * Copyright © 2001-2011 Stéphane Raimbault <stephane.raimbault@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef MODBUS_AUDP_PRIVATE_H
#define MODBUS_AUDP_PRIVATE_H

#define _MODBUS_AUDP_HEADER_LENGTH      2
#define _MODBUS_AUDP_PRESET_REQ_LENGTH  7
#define _MODBUS_AUDP_PRESET_RSP_LENGTH  2

#define _MODBUS_AUDP_CHECKSUM_LENGTH    3

/* In both structures, the transaction ID must be placed on first position
   to have a quick access not dependant of the TCP backend */
typedef struct _modbus_audp {
    uint16_t t_id;
    /* TCP port */
    int port;
    /* IP address */
    char ip[16];
	struct sockaddr_in addr;
	char rx_buff[1024];
	int rxlen;
} modbus_audp_t;

#define _MODBUS_AUDP_PI_NODE_LENGTH    1025
#define _MODBUS_AUDP_PI_SERVICE_LENGTH   32

typedef struct _modbus_audp_pi {
    /* Transaction ID */
    uint16_t t_id;
    /* TCP port */
    int port;
    /* Node */
    char node[_MODBUS_AUDP_PI_NODE_LENGTH];
    /* Service */
    char service[_MODBUS_AUDP_PI_SERVICE_LENGTH];
	/* To handle many slaves on the same link */
    int confirmation_to_ignore;
} modbus_audp_pi_t;

#endif /* MODBUS_TCP_PRIVATE_H */
