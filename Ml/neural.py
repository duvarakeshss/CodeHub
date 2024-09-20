import numpy as np
import tensorflow as tf
from tensorflow.keras import layers, models
from tensorflow.keras.datasets import mnist
from tensorflow.keras.utils import to_categorical

class DigitClassifier:
    def __init__(self):
        # Load and preprocess the MNIST dataset
        (self.train_images, self.train_labels), (self.test_images, self.test_labels) = mnist.load_data()
        self._preprocess_data()

        # Build the model
        self.model = self._build_model()

    def _preprocess_data(self):
        # Normalize the pixel values (from 0-255 to 0-1)
        self.train_images = self.train_images.astype('float32') / 255
        self.test_images = self.test_images.astype('float32') / 255

        # Reshape the images to include a channel dimension (required for Conv2D layers)
        self.train_images = self.train_images.reshape((self.train_images.shape[0], 28, 28, 1))
        self.test_images = self.test_images.reshape((self.test_images.shape[0], 28, 28, 1))

        # Convert labels to one-hot encoded vectors
        self.train_labels = to_categorical(self.train_labels)
        self.test_labels = to_categorical(self.test_labels)

    def _build_model(self):
        # Create the neural network model
        model = models.Sequential()

        # Add layers to the model
        model.add(layers.Conv2D(32, (3, 3), activation='relu', input_shape=(28, 28, 1)))
        model.add(layers.MaxPooling2D((2, 2)))
        model.add(layers.Conv2D(64, (3, 3), activation='relu'))
        model.add(layers.MaxPooling2D((2, 2)))
        model.add(layers.Conv2D(64, (3, 3), activation='relu'))

        # Flatten the data before passing it into a dense layer
        model.add(layers.Flatten())

        # Add a dense layer
        model.add(layers.Dense(64, activation='relu'))

        # Add the output layer with 10 classes (for digits 0-9)
        model.add(layers.Dense(10, activation='softmax'))

        # Compile the model
        model.compile(optimizer='adam',
                      loss='categorical_crossentropy',
                      metrics=['accuracy'])
        return model

    def train(self, epochs=5, batch_size=64):
        # Train the model
        self.model.fit(self.train_images, self.train_labels, epochs=epochs, batch_size=batch_size)

    def evaluate(self):
        # Evaluate the model on the test data
        test_loss, test_acc = self.model.evaluate(self.test_images, self.test_labels)
        print(f'Test accuracy: {test_acc:.4f}')
        return test_acc

    def save_model(self, filename='digit_classifier.h5'):
        # Save the trained model to a file
        self.model.save(filename)
        print(f"Model trained and saved as '{filename}'")


if __name__ == "__main__":
    classifier = DigitClassifier()
    classifier.train(epochs=5, batch_size=64)
    classifier.evaluate()
    classifier.save_model()
