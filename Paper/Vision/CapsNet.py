import tensorflow as tf
'''
Args :
    input : [batch_size, 20, 20, 256] or Output of Conv1 Layer\
    num_outputs : the number of capsule in this layer. At paper 32
    vec_len : integer, the length of the output vector of a capsule. At paper 8
    kernel_size : [9, 9]
    stride : 2

'''
capsules = []

for i in range(vec_len):
    with tf.variable_scope('ConvUnit_', + str(i)):
        caps_i = tf.contrib.layers.conv2d
