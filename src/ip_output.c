#include "syshead.h"
#include "utils.h"
#include "ipv4.h"
#include "arp.h"

void ip_send_check(struct iphdr *ihdr)
{

}

int ip_queue_xmit(struct tcp_socket *sock, struct sk_buff *skb)
{
    struct iphdr *ihdr;
    skb_push(skb, IP_HDR_LEN);

    ihdr = ip_hdr(skb);

    ihdr->saddr = htons(sock->saddr);
    ihdr->daddr = htons(sock->daddr);
    ihdr->len = htons(IP_HDR_LEN);
    ihdr->csum = 0;
    
    ip_send_check(ihdr);
    return neigh_resolve_output(skb);
}

int ip_output(struct sk_buff *skb)
{
    /* struct iphdr *iphdr = (struct iphdr *)hdr->payload; */
    /* uint32_t tmpaddr; */
    /* uint16_t csum; */
    /* uint8_t len = iphdr->len; */

    /* /\* Just swap the source and destination IP addresses, */
    /*  * don't bother with ARP lookup just now */
    /*  *\/ */
    /* tmpaddr = iphdr->saddr; */
    /* iphdr->daddr = tmpaddr; */
    /* iphdr->saddr = netdev->addr; */

    /* /\* */
    /*  * Switch back the necessary fields to Network Byte Order */
    /*  *\/ */
    /* iphdr->len = htons(iphdr->len); */

    /* /\* Calculate and set datagram checksum *\/ */
    /* iphdr->csum = 0; */
    /* csum = checksum(iphdr, iphdr->ihl * 4, 0); */
    /* iphdr->csum = csum; */

    /* netdev_transmit(netdev, hdr, ETH_P_IP, len, hdr->smac); */
    return 0;
}
