import matplotlib.pyplot as plt

k_values = [2,3,4,5]
acc1 = [0.8079,0.8232,0.8446,0.8656] #a-zA-Z0-9
f1s1 = [0.7902,0.8029,0.8251,0.8511]
time1 = [11+27,24+40,56+49,84+44]
acc2 = [0.8019,0.8190,0.8384,0.8584] #a-z0-9
f1s2 = [0.7846,0.7979,0.8177,0.8426]
time2 = [11+18,17+22,49+35,83+36]
acc3 = [0.7987,0.8185,0.8386,0.8598] #a-z
f1s3 = [0.7820,0.7968,0.8175,0.8440]
time3 = [9+12,13+16,41+30,82+32]
acc4 = [0.8059,0.8231,0.8441,0.8640] #a-zA-Z
f1s4 = [0.7880,0.8020,0.8243,0.8490]
time4 = [9+21,21+34,55+46,89+44]
acc5 = [0.7980,0.8151,0.8287,0.8387]
f1s5 = [0.7950,0.8103,0.8242,0.8348]
time5 = [11+26,18+28,35+34,65+39]

# Plot the lines with labels
"""
plt.plot(k_values, acc1, label='Accuracy for a-zA-Z0-9')
plt.plot(k_values, acc2, label='Accuracy for a-z0-9')
plt.plot(k_values, acc3, label='Accuracy for a-z')
plt.plot(k_values, acc4, label='Accuracy for a-zA-Z')
plt.plot(k_values, acc5, label='Accuracy for a-zA-Z0-9\s')

# Add labels and title
plt.xlabel('K values')
plt.ylabel('Accuracy')
plt.title('Accuracies relative to K values and input data')

# Add legend
plt.legend()

# Display the plot
plt.savefig('fig.png')
"""
"""
plt.plot(k_values, f1s1, label='F1 score for a-zA-Z0-9')
plt.plot(k_values, f1s2, label='F1 score for a-z0-9')
plt.plot(k_values, f1s3, label='F1 score for a-z')
plt.plot(k_values, f1s4, label='F1 score for a-zA-Z')
plt.plot(k_values, f1s5, label='F1 score for a-zA-Z0-9\s')

# Add labels and title
plt.xlabel('K values')
plt.ylabel('F1 score')
plt.title('F1 scores relative to K values and input data')

# Add legend
plt.legend()

# Display the plot
plt.savefig('fig2.png')
"""

plt.plot(k_values, time1, label='Execution time for a-zA-Z0-9')
plt.plot(k_values, time2, label='Execution time for a-z0-9')
plt.plot(k_values, time3, label='Execution time for a-z')
plt.plot(k_values, time4, label='Execution time for a-zA-Z')
plt.plot(k_values, time5, label='Execution time for a-zA-Z0-9\s')

# Add labels and title
plt.xlabel('K values')
plt.ylabel('Execution time (in seconds)')
plt.title('Execution times relative to K values and input data')

# Add legend
plt.legend()

# Display the plot
plt.savefig('fig3.png')