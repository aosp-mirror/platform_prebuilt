/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef __LINUX_RTNETLINK_H
#define __LINUX_RTNETLINK_H

#include <linux/netlink.h>

enum {
 RTM_BASE = 16,
#define RTM_BASE RTM_BASE

 RTM_NEWLINK = 16,
#define RTM_NEWLINK RTM_NEWLINK
 RTM_DELLINK,
#define RTM_DELLINK RTM_DELLINK
 RTM_GETLINK,
#define RTM_GETLINK RTM_GETLINK
 RTM_SETLINK,
#define RTM_SETLINK RTM_SETLINK

 RTM_NEWADDR = 20,
#define RTM_NEWADDR RTM_NEWADDR
 RTM_DELADDR,
#define RTM_DELADDR RTM_DELADDR
 RTM_GETADDR,
#define RTM_GETADDR RTM_GETADDR

 RTM_NEWROUTE = 24,
#define RTM_NEWROUTE RTM_NEWROUTE
 RTM_DELROUTE,
#define RTM_DELROUTE RTM_DELROUTE
 RTM_GETROUTE,
#define RTM_GETROUTE RTM_GETROUTE

 RTM_NEWNEIGH = 28,
#define RTM_NEWNEIGH RTM_NEWNEIGH
 RTM_DELNEIGH,
#define RTM_DELNEIGH RTM_DELNEIGH
 RTM_GETNEIGH,
#define RTM_GETNEIGH RTM_GETNEIGH

 RTM_NEWRULE = 32,
#define RTM_NEWRULE RTM_NEWRULE
 RTM_DELRULE,
#define RTM_DELRULE RTM_DELRULE
 RTM_GETRULE,
#define RTM_GETRULE RTM_GETRULE

 RTM_NEWQDISC = 36,
#define RTM_NEWQDISC RTM_NEWQDISC
 RTM_DELQDISC,
#define RTM_DELQDISC RTM_DELQDISC
 RTM_GETQDISC,
#define RTM_GETQDISC RTM_GETQDISC

 RTM_NEWTCLASS = 40,
#define RTM_NEWTCLASS RTM_NEWTCLASS
 RTM_DELTCLASS,
#define RTM_DELTCLASS RTM_DELTCLASS
 RTM_GETTCLASS,
#define RTM_GETTCLASS RTM_GETTCLASS

 RTM_NEWTFILTER = 44,
#define RTM_NEWTFILTER RTM_NEWTFILTER
 RTM_DELTFILTER,
#define RTM_DELTFILTER RTM_DELTFILTER
 RTM_GETTFILTER,
#define RTM_GETTFILTER RTM_GETTFILTER

 RTM_NEWACTION = 48,
#define RTM_NEWACTION RTM_NEWACTION
 RTM_DELACTION,
#define RTM_DELACTION RTM_DELACTION
 RTM_GETACTION,
#define RTM_GETACTION RTM_GETACTION

 RTM_NEWPREFIX = 52,
#define RTM_NEWPREFIX RTM_NEWPREFIX
 RTM_GETPREFIX = 54,
#define RTM_GETPREFIX RTM_GETPREFIX

 RTM_GETMULTICAST = 58,
#define RTM_GETMULTICAST RTM_GETMULTICAST

 RTM_GETANYCAST = 62,
#define RTM_GETANYCAST RTM_GETANYCAST

 RTM_NEWNEIGHTBL = 64,
#define RTM_NEWNEIGHTBL RTM_NEWNEIGHTBL
 RTM_GETNEIGHTBL = 66,
#define RTM_GETNEIGHTBL RTM_GETNEIGHTBL
 RTM_SETNEIGHTBL,
#define RTM_SETNEIGHTBL RTM_SETNEIGHTBL

 __RTM_MAX,
#define RTM_MAX (((__RTM_MAX + 3) & ~3) - 1)
};

#define RTM_NR_MSGTYPES (RTM_MAX + 1 - RTM_BASE)
#define RTM_NR_FAMILIES (RTM_NR_MSGTYPES >> 2)
#define RTM_FAM(cmd) (((cmd) - RTM_BASE) >> 2)

struct rtattr
{
 unsigned short rta_len;
 unsigned short rta_type;
};

#define RTA_ALIGNTO 4
#define RTA_ALIGN(len) ( ((len)+RTA_ALIGNTO-1) & ~(RTA_ALIGNTO-1) )
#define RTA_OK(rta,len) ((len) >= (int)sizeof(struct rtattr) &&   (rta)->rta_len >= sizeof(struct rtattr) &&   (rta)->rta_len <= (len))
#define RTA_NEXT(rta,attrlen) ((attrlen) -= RTA_ALIGN((rta)->rta_len),   (struct rtattr*)(((char*)(rta)) + RTA_ALIGN((rta)->rta_len)))
#define RTA_LENGTH(len) (RTA_ALIGN(sizeof(struct rtattr)) + (len))
#define RTA_SPACE(len) RTA_ALIGN(RTA_LENGTH(len))
#define RTA_DATA(rta) ((void*)(((char*)(rta)) + RTA_LENGTH(0)))
#define RTA_PAYLOAD(rta) ((int)((rta)->rta_len) - RTA_LENGTH(0))

struct rtmsg
{
 unsigned char rtm_family;
 unsigned char rtm_dst_len;
 unsigned char rtm_src_len;
 unsigned char rtm_tos;

 unsigned char rtm_table;
 unsigned char rtm_protocol;
 unsigned char rtm_scope;
 unsigned char rtm_type;

 unsigned rtm_flags;
};

enum
{
 RTN_UNSPEC,
 RTN_UNICAST,
 RTN_LOCAL,
 RTN_BROADCAST,
 RTN_ANYCAST,
 RTN_MULTICAST,
 RTN_BLACKHOLE,
 RTN_UNREACHABLE,
 RTN_PROHIBIT,
 RTN_THROW,
 RTN_NAT,
 RTN_XRESOLVE,
 __RTN_MAX
};

#define RTN_MAX (__RTN_MAX - 1)

#define RTPROT_UNSPEC 0
#define RTPROT_REDIRECT 1  
#define RTPROT_KERNEL 2  
#define RTPROT_BOOT 3  
#define RTPROT_STATIC 4  

#define RTPROT_GATED 8  
#define RTPROT_RA 9  
#define RTPROT_MRT 10  
#define RTPROT_ZEBRA 11  
#define RTPROT_BIRD 12  
#define RTPROT_DNROUTED 13  
#define RTPROT_XORP 14  
#define RTPROT_NTK 15  

enum rt_scope_t
{
 RT_SCOPE_UNIVERSE=0,

 RT_SCOPE_SITE=200,
 RT_SCOPE_LINK=253,
 RT_SCOPE_HOST=254,
 RT_SCOPE_NOWHERE=255
};

#define RTM_F_NOTIFY 0x100  
#define RTM_F_CLONED 0x200  
#define RTM_F_EQUALIZE 0x400  
#define RTM_F_PREFIX 0x800  

enum rt_class_t
{
 RT_TABLE_UNSPEC=0,

 RT_TABLE_DEFAULT=253,
 RT_TABLE_MAIN=254,
 RT_TABLE_LOCAL=255,
 __RT_TABLE_MAX
};
#define RT_TABLE_MAX (__RT_TABLE_MAX - 1)

enum rtattr_type_t
{
 RTA_UNSPEC,
 RTA_DST,
 RTA_SRC,
 RTA_IIF,
 RTA_OIF,
 RTA_GATEWAY,
 RTA_PRIORITY,
 RTA_PREFSRC,
 RTA_METRICS,
 RTA_MULTIPATH,
 RTA_PROTOINFO,
 RTA_FLOW,
 RTA_CACHEINFO,
 RTA_SESSION,
 RTA_MP_ALGO,
 __RTA_MAX
};

#define RTA_MAX (__RTA_MAX - 1)

#define RTM_RTA(r) ((struct rtattr*)(((char*)(r)) + NLMSG_ALIGN(sizeof(struct rtmsg))))
#define RTM_PAYLOAD(n) NLMSG_PAYLOAD(n,sizeof(struct rtmsg))

struct rtnexthop
{
 unsigned short rtnh_len;
 unsigned char rtnh_flags;
 unsigned char rtnh_hops;
 int rtnh_ifindex;
};

#define RTNH_F_DEAD 1  
#define RTNH_F_PERVASIVE 2  
#define RTNH_F_ONLINK 4  

#define RTNH_ALIGNTO 4
#define RTNH_ALIGN(len) ( ((len)+RTNH_ALIGNTO-1) & ~(RTNH_ALIGNTO-1) )
#define RTNH_OK(rtnh,len) ((rtnh)->rtnh_len >= sizeof(struct rtnexthop) &&   ((int)(rtnh)->rtnh_len) <= (len))
#define RTNH_NEXT(rtnh) ((struct rtnexthop*)(((char*)(rtnh)) + RTNH_ALIGN((rtnh)->rtnh_len)))
#define RTNH_LENGTH(len) (RTNH_ALIGN(sizeof(struct rtnexthop)) + (len))
#define RTNH_SPACE(len) RTNH_ALIGN(RTNH_LENGTH(len))
#define RTNH_DATA(rtnh) ((struct rtattr*)(((char*)(rtnh)) + RTNH_LENGTH(0)))

struct rta_cacheinfo
{
 __u32 rta_clntref;
 __u32 rta_lastuse;
 __s32 rta_expires;
 __u32 rta_error;
 __u32 rta_used;

#define RTNETLINK_HAVE_PEERINFO 1
 __u32 rta_id;
 __u32 rta_ts;
 __u32 rta_tsage;
};

enum
{
 RTAX_UNSPEC,
#define RTAX_UNSPEC RTAX_UNSPEC
 RTAX_LOCK,
#define RTAX_LOCK RTAX_LOCK
 RTAX_MTU,
#define RTAX_MTU RTAX_MTU
 RTAX_WINDOW,
#define RTAX_WINDOW RTAX_WINDOW
 RTAX_RTT,
#define RTAX_RTT RTAX_RTT
 RTAX_RTTVAR,
#define RTAX_RTTVAR RTAX_RTTVAR
 RTAX_SSTHRESH,
#define RTAX_SSTHRESH RTAX_SSTHRESH
 RTAX_CWND,
#define RTAX_CWND RTAX_CWND
 RTAX_ADVMSS,
#define RTAX_ADVMSS RTAX_ADVMSS
 RTAX_REORDERING,
#define RTAX_REORDERING RTAX_REORDERING
 RTAX_HOPLIMIT,
#define RTAX_HOPLIMIT RTAX_HOPLIMIT
 RTAX_INITCWND,
#define RTAX_INITCWND RTAX_INITCWND
 RTAX_FEATURES,
#define RTAX_FEATURES RTAX_FEATURES
 __RTAX_MAX
};

#define RTAX_MAX (__RTAX_MAX - 1)

#define RTAX_FEATURE_ECN 0x00000001
#define RTAX_FEATURE_SACK 0x00000002
#define RTAX_FEATURE_TIMESTAMP 0x00000004
#define RTAX_FEATURE_ALLFRAG 0x00000008

struct rta_session
{
 __u8 proto;
 __u8 pad1;
 __u16 pad2;

 union {
 struct {
 __u16 sport;
 __u16 dport;
 } ports;

 struct {
 __u8 type;
 __u8 code;
 __u16 ident;
 } icmpt;

 __u32 spi;
 } u;
};

struct ifaddrmsg
{
 unsigned char ifa_family;
 unsigned char ifa_prefixlen;
 unsigned char ifa_flags;
 unsigned char ifa_scope;
 int ifa_index;
};

enum
{
 IFA_UNSPEC,
 IFA_ADDRESS,
 IFA_LOCAL,
 IFA_LABEL,
 IFA_BROADCAST,
 IFA_ANYCAST,
 IFA_CACHEINFO,
 IFA_MULTICAST,
 __IFA_MAX
};

#define IFA_MAX (__IFA_MAX - 1)

#define IFA_F_SECONDARY 0x01
#define IFA_F_TEMPORARY IFA_F_SECONDARY

#define IFA_F_DEPRECATED 0x20
#define IFA_F_TENTATIVE 0x40
#define IFA_F_PERMANENT 0x80

struct ifa_cacheinfo
{
 __u32 ifa_prefered;
 __u32 ifa_valid;
 __u32 cstamp;
 __u32 tstamp;
};

#define IFA_RTA(r) ((struct rtattr*)(((char*)(r)) + NLMSG_ALIGN(sizeof(struct ifaddrmsg))))
#define IFA_PAYLOAD(n) NLMSG_PAYLOAD(n,sizeof(struct ifaddrmsg))

struct ndmsg
{
 unsigned char ndm_family;
 unsigned char ndm_pad1;
 unsigned short ndm_pad2;
 int ndm_ifindex;
 __u16 ndm_state;
 __u8 ndm_flags;
 __u8 ndm_type;
};

enum
{
 NDA_UNSPEC,
 NDA_DST,
 NDA_LLADDR,
 NDA_CACHEINFO,
 NDA_PROBES,
 __NDA_MAX
};

#define NDA_MAX (__NDA_MAX - 1)

#define NDA_RTA(r) ((struct rtattr*)(((char*)(r)) + NLMSG_ALIGN(sizeof(struct ndmsg))))
#define NDA_PAYLOAD(n) NLMSG_PAYLOAD(n,sizeof(struct ndmsg))

#define NTF_PROXY 0x08  
#define NTF_ROUTER 0x80

#define NUD_INCOMPLETE 0x01
#define NUD_REACHABLE 0x02
#define NUD_STALE 0x04
#define NUD_DELAY 0x08
#define NUD_PROBE 0x10
#define NUD_FAILED 0x20

#define NUD_NOARP 0x40
#define NUD_PERMANENT 0x80
#define NUD_NONE 0x00

struct nda_cacheinfo
{
 __u32 ndm_confirmed;
 __u32 ndm_used;
 __u32 ndm_updated;
 __u32 ndm_refcnt;
};

struct ndt_stats
{
 __u64 ndts_allocs;
 __u64 ndts_destroys;
 __u64 ndts_hash_grows;
 __u64 ndts_res_failed;
 __u64 ndts_lookups;
 __u64 ndts_hits;
 __u64 ndts_rcv_probes_mcast;
 __u64 ndts_rcv_probes_ucast;
 __u64 ndts_periodic_gc_runs;
 __u64 ndts_forced_gc_runs;
};

enum {
 NDTPA_UNSPEC,
 NDTPA_IFINDEX,
 NDTPA_REFCNT,
 NDTPA_REACHABLE_TIME,
 NDTPA_BASE_REACHABLE_TIME,
 NDTPA_RETRANS_TIME,
 NDTPA_GC_STALETIME,
 NDTPA_DELAY_PROBE_TIME,
 NDTPA_QUEUE_LEN,
 NDTPA_APP_PROBES,
 NDTPA_UCAST_PROBES,
 NDTPA_MCAST_PROBES,
 NDTPA_ANYCAST_DELAY,
 NDTPA_PROXY_DELAY,
 NDTPA_PROXY_QLEN,
 NDTPA_LOCKTIME,
 __NDTPA_MAX
};
#define NDTPA_MAX (__NDTPA_MAX - 1)

struct ndtmsg
{
 __u8 ndtm_family;
 __u8 ndtm_pad1;
 __u16 ndtm_pad2;
};

struct ndt_config
{
 __u16 ndtc_key_len;
 __u16 ndtc_entry_size;
 __u32 ndtc_entries;
 __u32 ndtc_last_flush;
 __u32 ndtc_last_rand;
 __u32 ndtc_hash_rnd;
 __u32 ndtc_hash_mask;
 __u32 ndtc_hash_chain_gc;
 __u32 ndtc_proxy_qlen;
};

enum {
 NDTA_UNSPEC,
 NDTA_NAME,
 NDTA_THRESH1,
 NDTA_THRESH2,
 NDTA_THRESH3,
 NDTA_CONFIG,
 NDTA_PARMS,
 NDTA_STATS,
 NDTA_GC_INTERVAL,
 __NDTA_MAX
};
#define NDTA_MAX (__NDTA_MAX - 1)

#define NDTA_RTA(r) ((struct rtattr*)(((char*)(r)) +   NLMSG_ALIGN(sizeof(struct ndtmsg))))
#define NDTA_PAYLOAD(n) NLMSG_PAYLOAD(n,sizeof(struct ndtmsg))

struct rtgenmsg
{
 unsigned char rtgen_family;
};

struct ifinfomsg
{
 unsigned char ifi_family;
 unsigned char __ifi_pad;
 unsigned short ifi_type;
 int ifi_index;
 unsigned ifi_flags;
 unsigned ifi_change;
};

struct prefixmsg
{
 unsigned char prefix_family;
 unsigned char prefix_pad1;
 unsigned short prefix_pad2;
 int prefix_ifindex;
 unsigned char prefix_type;
 unsigned char prefix_len;
 unsigned char prefix_flags;
 unsigned char prefix_pad3;
};

enum
{
 PREFIX_UNSPEC,
 PREFIX_ADDRESS,
 PREFIX_CACHEINFO,
 __PREFIX_MAX
};

#define PREFIX_MAX (__PREFIX_MAX - 1)

struct prefix_cacheinfo
{
 __u32 preferred_time;
 __u32 valid_time;
};

struct rtnl_link_stats
{
 __u32 rx_packets;
 __u32 tx_packets;
 __u32 rx_bytes;
 __u32 tx_bytes;
 __u32 rx_errors;
 __u32 tx_errors;
 __u32 rx_dropped;
 __u32 tx_dropped;
 __u32 multicast;
 __u32 collisions;

 __u32 rx_length_errors;
 __u32 rx_over_errors;
 __u32 rx_crc_errors;
 __u32 rx_frame_errors;
 __u32 rx_fifo_errors;
 __u32 rx_missed_errors;

 __u32 tx_aborted_errors;
 __u32 tx_carrier_errors;
 __u32 tx_fifo_errors;
 __u32 tx_heartbeat_errors;
 __u32 tx_window_errors;

 __u32 rx_compressed;
 __u32 tx_compressed;
};

struct rtnl_link_ifmap
{
 __u64 mem_start;
 __u64 mem_end;
 __u64 base_addr;
 __u16 irq;
 __u8 dma;
 __u8 port;
};

enum
{
 IFLA_UNSPEC,
 IFLA_ADDRESS,
 IFLA_BROADCAST,
 IFLA_IFNAME,
 IFLA_MTU,
 IFLA_LINK,
 IFLA_QDISC,
 IFLA_STATS,
 IFLA_COST,
#define IFLA_COST IFLA_COST
 IFLA_PRIORITY,
#define IFLA_PRIORITY IFLA_PRIORITY
 IFLA_MASTER,
#define IFLA_MASTER IFLA_MASTER
 IFLA_WIRELESS,
#define IFLA_WIRELESS IFLA_WIRELESS
 IFLA_PROTINFO,
#define IFLA_PROTINFO IFLA_PROTINFO
 IFLA_TXQLEN,
#define IFLA_TXQLEN IFLA_TXQLEN
 IFLA_MAP,
#define IFLA_MAP IFLA_MAP
 IFLA_WEIGHT,
#define IFLA_WEIGHT IFLA_WEIGHT
 IFLA_OPERSTATE,
 IFLA_LINKMODE,
 __IFLA_MAX
};

#define IFLA_MAX (__IFLA_MAX - 1)

#define IFLA_RTA(r) ((struct rtattr*)(((char*)(r)) + NLMSG_ALIGN(sizeof(struct ifinfomsg))))
#define IFLA_PAYLOAD(n) NLMSG_PAYLOAD(n,sizeof(struct ifinfomsg))

enum
{
 IFLA_INET6_UNSPEC,
 IFLA_INET6_FLAGS,
 IFLA_INET6_CONF,
 IFLA_INET6_STATS,
 IFLA_INET6_MCAST,
 IFLA_INET6_CACHEINFO,
 __IFLA_INET6_MAX
};

#define IFLA_INET6_MAX (__IFLA_INET6_MAX - 1)

struct ifla_cacheinfo
{
 __u32 max_reasm_len;
 __u32 tstamp;
 __u32 reachable_time;
 __u32 retrans_time;
};

struct tcmsg
{
 unsigned char tcm_family;
 unsigned char tcm__pad1;
 unsigned short tcm__pad2;
 int tcm_ifindex;
 __u32 tcm_handle;
 __u32 tcm_parent;
 __u32 tcm_info;
};

enum
{
 TCA_UNSPEC,
 TCA_KIND,
 TCA_OPTIONS,
 TCA_STATS,
 TCA_XSTATS,
 TCA_RATE,
 TCA_FCNT,
 TCA_STATS2,
 __TCA_MAX
};

#define TCA_MAX (__TCA_MAX - 1)

#define TCA_RTA(r) ((struct rtattr*)(((char*)(r)) + NLMSG_ALIGN(sizeof(struct tcmsg))))
#define TCA_PAYLOAD(n) NLMSG_PAYLOAD(n,sizeof(struct tcmsg))

#define RTMGRP_LINK 1
#define RTMGRP_NOTIFY 2
#define RTMGRP_NEIGH 4
#define RTMGRP_TC 8

#define RTMGRP_IPV4_IFADDR 0x10
#define RTMGRP_IPV4_MROUTE 0x20
#define RTMGRP_IPV4_ROUTE 0x40
#define RTMGRP_IPV4_RULE 0x80

#define RTMGRP_IPV6_IFADDR 0x100
#define RTMGRP_IPV6_MROUTE 0x200
#define RTMGRP_IPV6_ROUTE 0x400
#define RTMGRP_IPV6_IFINFO 0x800

#define RTMGRP_DECnet_IFADDR 0x1000
#define RTMGRP_DECnet_ROUTE 0x4000

#define RTMGRP_IPV6_PREFIX 0x20000

enum rtnetlink_groups {
 RTNLGRP_NONE,
#define RTNLGRP_NONE RTNLGRP_NONE
 RTNLGRP_LINK,
#define RTNLGRP_LINK RTNLGRP_LINK
 RTNLGRP_NOTIFY,
#define RTNLGRP_NOTIFY RTNLGRP_NOTIFY
 RTNLGRP_NEIGH,
#define RTNLGRP_NEIGH RTNLGRP_NEIGH
 RTNLGRP_TC,
#define RTNLGRP_TC RTNLGRP_TC
 RTNLGRP_IPV4_IFADDR,
#define RTNLGRP_IPV4_IFADDR RTNLGRP_IPV4_IFADDR
 RTNLGRP_IPV4_MROUTE,
#define RTNLGRP_IPV4_MROUTE RTNLGRP_IPV4_MROUTE
 RTNLGRP_IPV4_ROUTE,
#define RTNLGRP_IPV4_ROUTE RTNLGRP_IPV4_ROUTE
 RTNLGRP_IPV4_RULE,
#define RTNLGRP_IPV4_RULE RTNLGRP_IPV4_RULE
 RTNLGRP_IPV6_IFADDR,
#define RTNLGRP_IPV6_IFADDR RTNLGRP_IPV6_IFADDR
 RTNLGRP_IPV6_MROUTE,
#define RTNLGRP_IPV6_MROUTE RTNLGRP_IPV6_MROUTE
 RTNLGRP_IPV6_ROUTE,
#define RTNLGRP_IPV6_ROUTE RTNLGRP_IPV6_ROUTE
 RTNLGRP_IPV6_IFINFO,
#define RTNLGRP_IPV6_IFINFO RTNLGRP_IPV6_IFINFO
 RTNLGRP_DECnet_IFADDR,
#define RTNLGRP_DECnet_IFADDR RTNLGRP_DECnet_IFADDR
 RTNLGRP_NOP2,
 RTNLGRP_DECnet_ROUTE,
#define RTNLGRP_DECnet_ROUTE RTNLGRP_DECnet_ROUTE
 RTNLGRP_NOP3,
 RTNLGRP_NOP4,
 RTNLGRP_IPV6_PREFIX,
#define RTNLGRP_IPV6_PREFIX RTNLGRP_IPV6_PREFIX
 __RTNLGRP_MAX
};
#define RTNLGRP_MAX (__RTNLGRP_MAX - 1)

struct tcamsg
{
 unsigned char tca_family;
 unsigned char tca__pad1;
 unsigned short tca__pad2;
};
#define TA_RTA(r) ((struct rtattr*)(((char*)(r)) + NLMSG_ALIGN(sizeof(struct tcamsg))))
#define TA_PAYLOAD(n) NLMSG_PAYLOAD(n,sizeof(struct tcamsg))
#define TCA_ACT_TAB 1   
#define TCAA_MAX 1

#endif
