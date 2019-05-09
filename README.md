# 42-Project-Ft_SSL_MD5
An introduction to cryptographic hashing algorithms.

In this project we are introduced to a couple cryptographic hashing algorithms: MD5, SHA-256, SHA-1, SHA-512.
Then we are asked to recreate them.

## Implemented Cryptographic Hashing Algorithms
<table>
  <tr>
    <th text-align=right>Algorithm</th>
    <th>Digest size</th>
    <th>Block size</th>
    <th>Words</th>
    <th>Rounds</th>
    <th>Checksum</th>
  </tr>
  <tr>
    <td>MD5</td>
    <td>128 bits<br>(4 * 32-bits)</td>
    <td>512 bits</td>
    <td>16 (32-bits each)</td>
    <td>64</td>
    <td>32 chars<br>(128 bits / 4)</td>
  </tr>
  <tr>
    <td>SHA-256</td>
    <td rowspan=2>256 bits<br>(8 * 32-bits)</td>
    <td rowspan=2>512 bits</td>
    <td rowspan=2>64 (32-bits each)</td>
    <td rowspan=2>64</td>
    <td>64 chars<br>(256 bits / 4)</td>
  </tr>
  <tr>
    <td>SHA-224</td>
    <td>56 chars<br>(224 bits) / 4)</td>
  </tr>
  <tr>
    <td>SHA-1</td>
    <td>160 bits<br>(5 * 32-bits)</td>
    <td>512 bits</td>
    <td>80 (32-bits each)</td>
    <td>80</td>
    <td>40 chars<br>(160 bits / 4)</td>
  </tr>
  <tr>
    <td>SHA-512</td>
    <td rowspan=2>512 bits<br>(8 * 64-bits)</td>
    <td rowspan=2>1024 bits</td>
    <td rowspan=2>80 (64-bits each)</td>
    <td rowspan=2>80</td>
    <td>128 chars<br>(512 bits / 4)</td>
  </tr>
  <tr>
    <td>SHA-384</td>
    <td>96 chars<br>(384 bits / 4)</td>
  </tr>
</table>

SHA-224 is a variant of SHA-256, and SHA-384 is a variant of SHA-512. (Made to run on little-endian machines)
