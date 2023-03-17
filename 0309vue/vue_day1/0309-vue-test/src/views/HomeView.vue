<template>
  <div>
    <h1>할배</h1>
    {{HalbeaData}}
    <HomeParent
      :HalbeaData="HalbeaData"
      :HalbeaData2="HalbeaData2"
      @changeHalbeaData="changeHalbeaData"
    />
  </div>
</template>

<script>
import HomeParent from "../components/HomeParent.vue";
export default {
  components: {
    HomeParent,
  },
  data() {
    return {
      HalbeaData: "나는 할배데이터",
      HalbeaData2: "asdfasdfsdf",
    };
  },
  methods: {
    changeHalbeaData(text) {
      this.HalbeaData=text;
    },
  },
};
</script>
