#include <stdio.h>
#include <errno.h>

int insert_header(int *packet, size_t *length)
{
    size_t i;
    char header[12] = {0x80, 0x52, 0x66, 0x61, 0x77, 0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    size_t header_size = (sizeof(header) / sizeof(int));

    if (packet == NULL || length == NULL)
    {
        return -EINVAL;
    }
    for (i = 0; i < (*length - header_size); i++)
        packet[i + header_size] = packet[i];

    for (i = 0; i < header_size; i++)
    {
        packet[i] = header[(i * sizeof(int))] << 24|
                    header[(i * sizeof(int)) + 1] << 16 |
                    header[(i * sizeof(int)) + 2] << 8 |
                    header[(i * sizeof(int)) + 3];
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    size_t i;
    int packet[8] = {1, 2, 3, 4, 5, 0, 0, 0};
    size_t packet_size = sizeof(packet) / sizeof(int);
    insert_header(packet, &packet_size);
    for (i = 0; i < packet_size; i++)
    {
        printf("%08x\n", packet[i]);
    }
    return 0;
}
