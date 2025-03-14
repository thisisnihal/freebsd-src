/*-
 * Copyright (c) 2010 Damien Bergamini <damien.bergamini@free.fr>
 * Copyright (c) 2016 Andriy Voskoboinyk <avos@FreeBSD.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * $OpenBSD: if_urtwnreg.h,v 1.3 2010/11/16 18:02:59 damien Exp $
 */

#ifndef R92C_TX_DESC_H
#define R92C_TX_DESC_H

/* Tx MAC descriptor (common part). */
struct r92c_tx_desc {
	uint16_t 	pktlen;
	uint8_t		offset;
	uint8_t		flags0;
#define R92C_FLAGS0_BMCAST	0x01
#define R92C_FLAGS0_LSG		0x04
#define R92C_FLAGS0_FSG		0x08
#define R92C_FLAGS0_OWN		0x80

	uint32_t	txdw1;
#define R92C_TXDW1_MACID_M	0x0000001f
#define R92C_TXDW1_MACID_S	0
#define R92C_TXDW1_AGGEN	0x00000020
#define R92C_TXDW1_AGGBK	0x00000040

#define R92C_TXDW1_QSEL_M	0x00001f00
#define R92C_TXDW1_QSEL_S	8

#define R92C_TXDW1_QSEL_BE	0x00	/* or 0x03 */
#define R92C_TXDW1_QSEL_BK	0x01	/* or 0x02 */
#define R92C_TXDW1_QSEL_VI	0x04	/* or 0x05 */
#define R92C_TXDW1_QSEL_VO	0x06	/* or 0x07 */
#define RTWN_MAX_TID		8

#define R92C_TXDW1_QSEL_BEACON	0x10
#define R92C_TXDW1_QSEL_MGNT	0x12

#define R92C_TXDW1_RAID_M	0x000f0000
#define R92C_TXDW1_RAID_S	16
#define R92C_TXDW1_CIPHER_M	0x00c00000
#define R92C_TXDW1_CIPHER_S	22
#define R92C_TXDW1_CIPHER_NONE	0
#define R92C_TXDW1_CIPHER_RC4	1
#define R92C_TXDW1_CIPHER_AES	3
#define R92C_TXDW1_PKTOFF_M	0x7c000000
#define R92C_TXDW1_PKTOFF_S	26

	uint32_t	txdw2;
#define R92C_TXDW2_CCX_RPT	0x00080000
#define R92C_TXDW2_AMPDU_DEN_M	0x00700000
#define R92C_TXDW2_AMPDU_DEN_S	20

	uint16_t	txdw3;
	uint16_t	txdseq;

	uint32_t	txdw4;
#define R92C_TXDW4_RTSRATE_M	0x0000001f
#define R92C_TXDW4_RTSRATE_S	0
#define R92C_TXDW4_QOS		0x00000040 /* BIT(6) for 8188cu/8192cu/8723au */
#define R92C_TXDW4_HWSEQ_EN	0x00000080
#define R92C_TXDW4_DRVRATE	0x00000100
#define R92C_TXDW4_CTS2SELF	0x00000800
#define R92C_TXDW4_RTSEN	0x00001000
#define R92C_TXDW4_HWRTSEN	0x00002000
#define R92C_TXDW4_PORT_ID_M	0x00004000
#define R92C_TXDW4_PORT_ID_S	14
#define R92C_TXDW4_DATA_SCO_M	0x00300000
#define R92C_TXDW4_DATA_SCO_S	20
#define R92C_TXDW4_SCO_SCA	1
#define R92C_TXDW4_SCO_SCB	2
#define R92C_TXDW4_DATA_SHPRE	0x01000000
#define R92C_TXDW4_DATA_BW40	0x02000000
#define R92C_TXDW4_RTS_SHORT	0x04000000
#define R92C_TXDW4_RTS_BW40	0x08000000
#define R92C_TXDW4_RTS_SCO_M	0x30000000
#define R92C_TXDW4_RTS_SCO_S	28

	uint32_t	txdw5;
#define R92C_TXDW5_DATARATE_M		0x0000003f
#define R92C_TXDW5_DATARATE_S		0
#define R92C_TXDW5_SGI			0x00000040
#define R92C_TXDW5_DATARATE_FB_LMT_M	0x00001f00
#define R92C_TXDW5_DATARATE_FB_LMT_S	8
#define R92C_TXDW5_RTSRATE_FB_LMT_M	0x0001e000
#define R92C_TXDW5_RTSRATE_FB_LMT_S	13
#define R92C_TXDW5_RTY_LMT_ENA		0x00020000
#define R92C_TXDW5_RTY_LMT_M		0x00fc0000
#define R92C_TXDW5_RTY_LMT_S		18
#define R92C_TXDW5_AGGNUM_M		0xff000000
#define R92C_TXDW5_AGGNUM_S		24

	uint32_t	txdw6;
#define R92C_TXDW6_MAX_AGG_M		0x0000f800
#define R92C_TXDW6_MAX_AGG_S		11
} __packed __attribute__((aligned(4)));

/* Rate adaptation modes. */
#define R92C_RAID_11BGN		0
#define R92C_RAID_11GN		1
#define R92C_RAID_11BN		2
#define R92C_RAID_11N		3
#define R92C_RAID_11BG		4
#define R92C_RAID_11G		5	/* "pure" 11g */
#define R92C_RAID_11B		6

#endif	/* R92C_TX_DESC_H */
