/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 */

'use strict';

import React, {
  AppRegistry,
  Component,
  Image,
  StyleSheet,
  Text,
  View
} from 'react-native';

const DHCell = require('./DHCell');

class Project extends Component {
  render() {
    return (
      <View style={{paddingTop: 40}}>
        <DHCell
          subtitle='Subtitle'
          title='Title'
          uri='http://www.lyricsmode.com/i/bpictures/10381.png'
          >
        </DHCell>
        <DHCell
          subtitle='World'
          title='Hello'
          uri='http://www.datemplate.com/postpic/2012/01/looking-eyes-clip-art-free_283165.jpg'
          >
        </DHCell>
      </View>
    );
  }
}

AppRegistry.registerComponent('Project', () => Project);
